#include "planet.hpp"

Planet::Planet(int posX, int posY, float size)
: sf::CircleShape(size), _posX(posX), _posY(posY), _size(size) {
  setPosition(_posX, _posY);
  setOrigin(size, size);
  setFillColor(sf::Color::Green);
}

sf::Vector2f Planet::getAtraction(sf::Vector2f pos) const {
  std::cout << "\nPos planet x::" << getPosition().x << " y ::" << getPosition().y << std::endl;
  sf::Vector2f distDiff = getPosition() - pos;
  std::cout << "1 diff x ::" << distDiff.x << " y ::" << distDiff.y << std::endl;
  double dist = sqrt(pow(distDiff.x, 2) + pow(distDiff.y, 2));
  double diffSize = ABS((_size/dist) / 10000);
  distDiff.x *= diffSize;
  distDiff.y *= diffSize;
  std::cout << "2 diff x ::" << distDiff.x << " y ::" << distDiff.y << std::endl;
  return distDiff;
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
