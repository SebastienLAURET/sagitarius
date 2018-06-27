#include "ViewFinder.hpp"

ViewFinder::ViewFinder(int x, int y)
:sf::RectangleShape(sf::Vector2f(10, 1)),
_origine(sf::Vector2i(x, y)),
_fin(sf::Vector2i(x, y)) {
  setOrigin(0, 0);
  setPosition((float)_origine.x, (float)_origine.y);
}

void ViewFinder::update(int x, int y) {
  _fin = sf::Vector2i(x, y);
  setSize(sf::Vector2f((float)getVecLong(), 1));
  setRotation(getVecAngle());
}

sf::Vector2i ViewFinder::getMove() const {
  return _fin - _origine;
}

double ViewFinder::getVecLong() const {
  sf::Vector2i vec = getMove();
  return sqrt(pow(vec.x, 2) + pow(vec.y, 2));
}

double ViewFinder::getVecAngle() const {
  sf::Vector2i vec = getMove();
  return atan (vec.x/vec.y) * 180 / 3.14;
}
