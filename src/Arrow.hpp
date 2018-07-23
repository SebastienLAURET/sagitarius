#ifndef ARROW_HPP
#define ARROW_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <math.h>
#include "game_conf.hpp"

class Arrow : public sf::RectangleShape
{
private:
  std::chrono::high_resolution_clock::time_point _creation;
  std::chrono::high_resolution_clock::time_point _lastUpdate;

  sf::Vector2f _trajectoir;

public:
  Arrow(sf::Vector2f, sf::Vector2f);
  const sf::Vector2f &getTrajectoir() const;
  bool isAlive() const;

  void applyGravity(sf::Vector2f&gravity);
  void setTrajectoir(sf::Vector2f&);
  const sf::Vector2f &move();

private:
  void    updatePosition();
  void    adjustRotation();
  double  getVecLong() const;
};

#endif
