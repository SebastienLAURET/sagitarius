#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "planet.hpp"
#include "Arrow.hpp"
#include "game_conf.hpp"

class Player : public sf::RectangleShape
{
private:
  Planet& _planet;
  int     _posDeg;

public:

  Player(Planet &);

  const Planet &getPlanet() const;

  double getPosDeg();

  double goRight();
  double goLeft();

private:
  int move(int);
};

#endif
