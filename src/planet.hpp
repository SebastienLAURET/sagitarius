#ifndef PLANET_HPP
#define PLANET_HPP

#include <SFML/Graphics.hpp>

class Planet : public sf::CircleShape
{
private:
  int _posX;
  int _posY;
  int _size;

public:
  Planet(int posX, int posY, float size);

  int getPosX() const;
  int getPosY() const;
  int getSize() const;
};

#endif
