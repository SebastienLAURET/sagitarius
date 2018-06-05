#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include "planet.hpp"
#include "game_conf.hpp"

class Player : public sf::RectangleShape
{
private:
  Planet& _planet;
  int     _posDeg;

public:

  Player(Planet &planet);

  double getPosDeg();

  double goRight();
  double goLeft();

  int move(int);
};

#endif
