#include "planet.hpp"

Planet::Planet(int posX, int posY, float size)
: sf::CircleShape(size), _posX(posX), _posY(posY), _size(size) {
  setPosition(_posX, _posY);
  setOrigin(size, size);
  setFillColor(sf::Color::Green);
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
