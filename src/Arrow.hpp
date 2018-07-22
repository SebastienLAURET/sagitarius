#ifndef ARROW_HPP
#define ARROW_HPP

#include <SFML/Graphics.hpp>

class Arrow : public sf::RectangleShape
{
private:
  sf::Vector2i _trajectoir;

public:
  Arrow(sf::Vector2i, sf::Vector2f);

  const sf::Vector2i &getTrajectoir() const;

  void setTrajectoir(sf::Vector2i&);

  const sf::Vector2i &move();
};

#endif
