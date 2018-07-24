#include "planet.hpp"

Planet::Planet(int posX, int posY, float size)
: sf::CircleShape(size), _posX(posX), _posY(posY), _size(size) {
  setPosition(_posX, _posY);
  setOrigin(size, size);
  setFillColor(sf::Color::Green);
}

sf::Vector2f Planet::getAtraction(sf::Vector2f pos) const {
  sf::Vector2f distDiff = getPosition() - pos;
  double dist = sqrt(pow(distDiff.x, 2) + pow(distDiff.y, 2));
  double diffSize = ABS((_size/dist) / PLANET_RATE_GRAVITY);
  distDiff.x *= diffSize;
  distDiff.y *= diffSize;
  return distDiff;
}

bool Planet::isCollision(const Arrow *arrow) const {
  sf::Vector2f  distDiff = getPosition() - arrow->getPosition();
  double        dist = sqrt(pow(distDiff.x, 2) + pow(distDiff.y, 2));
  return dist <= _size;
}

int Planet::getPosX() const {
  return _posX;
}

int Planet::getPosY() const {
  return _posY;
}

int Planet::getSize() const {
  return _size;
}
