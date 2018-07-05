#include "player.hpp"

Player::Player(Planet &planet)
: sf::RectangleShape(sf::Vector2f(15, 4)), _planet(planet), _posDeg(0) {
  setFillColor(sf::Color::White);
  setOrigin(-_planet.getSize(), -2);
  setPosition(_planet.getPosX(), _planet.getPosY());
  setRotation(0);
}

const Planet &Player::getPlanet() const {
  return _planet;
}

double Player::goRight() {
  return move(DELTA_MOVE);
}

double Player::goLeft() {
  return move(-DELTA_MOVE);
}

int Player::move(int delta) {
  _posDeg = (_posDeg + delta) % 360;
  _posDeg = (_posDeg >= 0)? _posDeg : 360 + _posDeg;
  setRotation(_posDeg);
  return _posDeg;
}
