#ifndef UNIVAIRSE_HPP
# define UNIVAIRSE_HPP

#include <list>
#include "planet.hpp"
#include "player.hpp"
#include "Arrow.hpp"
#include "ViewFinder.hpp"

class Univairse {
private:
  std::list<Planet*>    _planets;
  std::vector<Player*>  _players;
  ViewFinder*           _vFinder = NULL;
  Arrow*                _arrow = NULL;
  int                   _indexPlayers = 0;
public:

  Univairse();

  bool                          isViewFinderActive() const;
  Player                        &getActualPlayer() const;
  void                          playerMoveLeft();
  void                          playerMoveRight();
  void                          playerActiveViewFinder(int x, int y);
  void                          playerUpdateViewFinder(int x, int y);
  void                          playerCancelViewFinder();

  void                          playerShoot();
  bool                          isArrowAlive();
  void                          updateArrow();

  const std::list<sf::Shape*>   *getDrawableObject() const;
private:
  void    initPlanets();
  void    initPlayers(Planet &planet);
  void    deleteViewFinder();
  sf::Vector2f  calculateGravity(sf::Vector2f) const;
};

#endif
