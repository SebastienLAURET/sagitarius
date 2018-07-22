#include "Arrow.hpp"

Arrow::Arrow(sf::Vector2i trajectoir, sf::Vector2f position)
: sf::RectangleShape(sf::Vector2f(5, 2)), _trajectoir(trajectoir) {
  setPosition(position);
}

const sf::Vector2i &Arrow::getTrajectoir() const {
  return _trajectoir;
}

void Arrow::setTrajectoir(sf::Vector2i& trajectoir) {
  _trajectoir = trajectoir;
}

const sf::Vector2i &Arrow::move() {

}
