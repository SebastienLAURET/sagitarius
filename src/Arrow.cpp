#include "Arrow.hpp"

Arrow::Arrow(sf::Vector2f trajectoir, sf::Vector2f position)
: sf::RectangleShape(sf::Vector2f(10, 4)), _trajectoir(trajectoir) {
  setPosition(position);
  _creation = std::chrono::high_resolution_clock::now();
  _lastUpdate = _creation;
  adjustRotation();
}

const sf::Vector2f &Arrow::getTrajectoir() const {
  return _trajectoir;
}

void Arrow::applyGravity(sf::Vector2f&gravity) {
  _trajectoir.x += gravity.x;
  _trajectoir.y -= gravity.y;
}

void Arrow::setTrajectoir(sf::Vector2f& trajectoir) {
  _trajectoir = trajectoir;
}

bool Arrow::isAlive() const {
  return (std::chrono::high_resolution_clock::now() - _creation).count() < ARROW_DURATION_LIFE;
}

const sf::Vector2f &Arrow::move() {
  std::chrono::duration<double> diffTime = std::chrono::high_resolution_clock::now() - _lastUpdate;
  if (diffTime.count() >= ARROW_DELTA_TIME) {
    _lastUpdate = std::chrono::high_resolution_clock::now();
    updatePosition();
    adjustRotation();
  }
  return getPosition();
}

void Arrow::updatePosition() {
  sf::Transform translation;

  sf::Vector2f newPos = translation.translate(_trajectoir.x * ARROW_RATE_MOVE_TIME, -_trajectoir.y * ARROW_RATE_MOVE_TIME)
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
