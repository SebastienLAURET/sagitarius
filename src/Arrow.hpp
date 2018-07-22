#ifndef ARROW_HPP
#define ARROW_HPP

#include <SFML/Graphics.hpp>
#include <chrono>
#include <math.h>
#include "game_conf.hpp"

class Arrow : public sf::RectangleShape
{
private:
  std::chrono::high_resolution_clock::time_point _creation;
  std::chrono::high_resolution_clock::time_point _lastUpdate;

  sf::Vector2i _trajectoir;

public:
  Arrow(sf::Vector2i, sf::Vector2f);
  const sf::Vector2i &getTrajectoir() const;
  bool isAlive() const;

  void setTrajectoir(sf::Vector2i&);
  const sf::Vector2f &move();

private:
  void    updatePosition();
  void    adjustRotation();
  double  getVecLong() const;
};

#endif
