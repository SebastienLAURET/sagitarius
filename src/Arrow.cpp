#include "Arrow.hpp"

Arrow::Arrow(sf::Vector2i trajectoir, sf::Vector2f position)
: sf::RectangleShape(sf::Vector2f(5, 2)), _trajectoir(trajectoir) {
  setPosition(position);
  _creation = std::chrono::high_resolution_clock::now();
  adjustRotation();
}

const sf::Vector2i &Arrow::getTrajectoir() const {
  return _trajectoir;
}

void Arrow::setTrajectoir(sf::Vector2i& trajectoir) {
  _trajectoir = trajectoir;
}
bool Arrow::isAlive() const {
  return (std::chrono::high_resolution_clock::now() - _lastUpdate).count() < ARROW_DURATION_LIFE;
}

const sf::Vector2f &Arrow::move() {
  std::chrono::duration<double> diffTime = std::chrono::high_resolution_clock::now() - _lastUpdate;
  if (diffTime.count() > ARROW_DELTA_TIME) {
    updatePosition();
    adjustRotation();
  }
  return getPosition();
}

void Arrow::updatePosition() {
  sf::Transform translation;
  sf::Vector2f newPos = translation.translate(_trajectoir.x, _trajectoir.y)
                      .transformPoint(getPosition());
  setPosition(newPos);
}

void Arrow::adjustRotation() {
  double        angle = 0;

  if (_trajectoir.y < 0)  {
    angle = (acos((double)_trajectoir.x/getVecLong()) * 180.0 / 3.14);
  } else if (_trajectoir.y > 0)  {
    angle = 360 - (acos((double)_trajectoir.x/getVecLong()) * 180.0 / 3.14);
  }
  setRotation(angle);
}

double Arrow::getVecLong() const {
  return sqrt(pow(_trajectoir.x, 2) + pow(_trajectoir.y, 2));
}
