#ifndef PLANET_HPP
#define PLANET_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "game_conf.hpp"

class Planet : public sf::CircleShape
{
private:
  int _posX;
  int _posY;
  int _size;

public:
  Planet(int posX, int posY, float size);

  sf::Vector2f getAtraction(sf::Vector2f pos) const;

  int getPosX() const;
  int getPosY() const;
  int getSize() const;
};

#endif
