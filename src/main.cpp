#include <SFML/Graphics.hpp>
#include <list>
#include <unistd.h>
#include "game_conf.hpp"
#include "planet.hpp"
#include "player.hpp"

int main()
{
  sf::RenderWindow window(sf::VideoMode(1600, 900), "SFML works!");
  std::list<sf::Shape*> listDrawableElem;
  Planet planet(500, 500, 100);
  Player player(planet);

  listDrawableElem.push_front(&player);
  listDrawableElem.push_front(&planet);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      } else if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Left)
          player.goLeft();
        if (event.key.code == sf::Keyboard::Right)
          player.goRight();
      }
    }
    window.clear();
    for (auto drawableElem: listDrawableElem) {
      window.draw(*drawableElem);
    }
    window.display();
    //sleep(1);
  }
  return 0;
}
