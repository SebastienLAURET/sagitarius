#include "ViewFinder.hpp"

ViewFinder::ViewFinder(int x, int y, Player &player)
:sf::RectangleShape(sf::Vector2f(10, 1)),
_origine(sf::Vector2i(x, y)),
_fin(sf::Vector2i(x, y)) {
  sf::Transform translation, rotation;
  sf::Vector2f trans, rot;

  trans = translation.translate(-player.getOrigin().x + player.getSize().x, 0)
                      .transformPoint(player.getPlanet().getPosition());
  rot = rotation.rotate(player.getRotation(),
                        (float)player.getPlanet().getPosition().x,
                        (float)player.getPlanet().getPosition().y)
                .transformPoint(trans);

  setOrigin(0, 0);
  setPosition(rot);
}

void ViewFinder::update(int x, int y) {
  _fin = sf::Vector2i(x, y);
  setSize(sf::Vector2f((float)getVecLong(), 1));
  setRotation(getVecAngle());
}

sf::Vector2f ViewFinder::getMove() const {
  return sf::Vector2f(_fin.x - _origine.x, _origine.y - _fin.y);
}

Arrow *ViewFinder::shootArrow() const {
  return new Arrow(getMove(), getPosition());
}

double ViewFinder::getVecLong() const {
  sf::Vector2f vec = getMove();
  return sqrt(pow(vec.x, 2) + pow(vec.y, 2));
}

double ViewFinder::getVecAngle() const {
  sf::Vector2f  vec = getMove();
  double        angle = 0;

  if (vec.y < 0)  {
    angle = (acos((double)vec.x/getVecLong()) * 180.0 / 3.14);
  } else if (vec.y > 0)  {
    angle = 360 - (acos((double)vec.x/getVecLong()) * 180.0 / 3.14);
  }
  return angle;
}
