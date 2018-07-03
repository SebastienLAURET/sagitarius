#include "ViewFinder.hpp"

ViewFinder::ViewFinder(int x, int y, Player &player)
:sf::RectangleShape(sf::Vector2f(10, 1)),
_origine(sf::Vector2i(x, y)),
_fin(sf::Vector2i(x, y)) {
  setOrigin(0, 0);
  setPosition((float)player.getPosition().x ,
              (float)player.getPosition().y);
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
