#include "ViewFinder.hpp"

ViewFinder::ViewFinder(int x, int y, Player &player)
:sf::RectangleShape(sf::Vector2f(10, 1)),
_origine(sf::Vector2i(x, y)),
_fin(sf::Vector2i(x, y)) {
  sf::Transform translation;
  sf::Transform rotation;
  sf::Transform transform;
  sf::Vector2f position;
  translation.translate(-player.getOrigin().x + player.getSize().x, 0);
  rotation.rotate(player.getRotation(),
                  (float)player.getPlanet().getPosition().x,
                  (float)player.getPlanet().getPosition().y);
  transform = translation * rotation;
  position = transform.transformPoint(player.getPlanet().getPosition());

  setOrigin(0, 0);
  setPosition(position);
}

void ViewFinder::update(int x, int y) {
  _fin = sf::Vector2i(x, y);
  setSize(sf::Vector2f((float)getVecLong(), 1));
  setRotation(getVecAngle());
}

sf::Vector2i ViewFinder::getMove() const {
  return sf::Vector2i(_fin.x - _origine.x, _origine.y - _fin.y);
}

double ViewFinder::getVecLong() const {
  sf::Vector2i vec = getMove();
  return sqrt(pow(vec.x, 2) + pow(vec.y, 2));
}

double ViewFinder::getVecAngle() const {
  sf::Vector2i  vec = getMove();
  double        angle = 0;

  if (vec.y < 0)  {
    angle = (acos((double)vec.x/getVecLong()) * 180.0 / 3.14);
  } else if (vec.y > 0)  {
    angle = 360 - (acos((double)vec.x/getVecLong()) * 180.0 / 3.14);
  }
  return angle;
}
