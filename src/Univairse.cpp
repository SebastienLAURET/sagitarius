#include "Univairse.hpp"

Univairse::Univairse() {
  initPlanets();
}

bool Univairse::isViewFinderActive() const {
  return _vFinder != NULL;
}

Player& Univairse::getActualPlayer() const {
  return *_players[_indexPlayers];
}

void Univairse::playerMoveLeft() {
  getActualPlayer().goLeft();
}

void Univairse::playerMoveRight() {
  getActualPlayer().goRight();
}

void Univairse::playerActiveViewFinder(int x, int y) {
  _vFinder = new ViewFinder(x, y, getActualPlayer());
}

void Univairse::playerUpdateViewFinder(int x, int y) {
  _vFinder->update(x, y);
}

void Univairse::playerCancelViewFinder() {
  deleteViewFinder();
}

void Univairse::playerShoot() {
  if (_vFinder) {
    _arrow = _vFinder->shootArrow();
    deleteViewFinder();
  }
}

void Univairse::updateArrow() {
  if (_arrow != NULL && _arrow->isAlive()) {
    calculateGravity(_arrow->getPosition());
    _arrow->move();
  } else if (_arrow != NULL) {
    delete _arrow;
    _arrow = NULL;
  }
}
bool  Univairse::isArrowAlive() {
  return _arrow != NULL;
}

const std::list<sf::Shape*> *Univairse::getDrawableObject() const {
  std::list<sf::Shape*> *drawableObject = new std::list<sf::Shape*>();

  for (auto elemPlannet : _planets) {
    drawableObject->push_front(elemPlannet);
  }
  for (auto elemPlayer : _players) {
    drawableObject->push_front(elemPlayer);
  }
  if (_vFinder) {
    drawableObject->push_front(_vFinder);
  }
  if (_arrow) {
    drawableObject->push_front(_arrow);
  }
  return drawableObject;
}


void Univairse::initPlanets() {
  Planet *tmpPlanet = new Planet(500, 500, 100);
  initPlayers(*tmpPlanet);
  _planets.push_front(tmpPlanet);
}

void Univairse::initPlayers(Planet &planet) {
    Player *player = new Player(planet);
    _players.push_back(player);
}


void Univairse::deleteViewFinder() {
  delete _vFinder;
  _vFinder = NULL;
}

sf::Vector2f  Univairse::calculateGravity(sf::Vector2f pos) const {
  sf::Vector2f  tra;
  for (auto planet : _planets) {
    tra = planet->getAtraction(pos);
  }
  return tra;
}
