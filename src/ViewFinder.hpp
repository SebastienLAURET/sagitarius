#ifndef VIEWFINDER_HPP
#define VIEWFINDER_HPP

#include <SFML/Graphics.hpp>
#include <math.h>
#include "player.hpp"
#include "Arrow.hpp"

class ViewFinder : public sf::RectangleShape
{
private:
  sf::Vector2i _origine;
  sf::Vector2i _fin;

public:
  ViewFinder(int x, int y, Player &player);

  void          update(int x, int y);
  sf::Vector2f  getMove() const;
  Arrow         *shootArrow() const;

private:
  double  getVecLong() const;
  double  getVecAngle() const;
};

#endif
