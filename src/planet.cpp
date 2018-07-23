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
  /*double coef = _size * PLANET_RATE_GRAVITY_SIZE / pow(PLANET_RATE_GRAVITY_DIST * dist, 2);
  */
  double angle;
  if (distDiff.y < 0)  {
    angle = (acos((double)distDiff.x/dist) * 180.0 / 3.14);
  } else if (distDiff.y > 0)  {
    angle = 360 - (acos((double)distDiff.x/dist) * 180.0 / 3.14);
  }
  std::cout <<"\nBefore x :: "<< distDiff.x << " y :: " << distDiff.y
            << " dist :: " << dist << std::endl;
  double diffSize = (_size/dist)/100 ;
  distDiff.x *= diffSize;
  distDiff.y *= diffSize;
  std::cout << "After x :: "<< distDiff.x << " y :: " << distDiff.y
            << " dist :: " << dist << std::endl;
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
