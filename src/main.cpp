#include <SFML/Graphics.hpp>
#include <list>
#include <unistd.h>
#include "game_conf.hpp"
#include "planet.hpp"
#include "player.hpp"
#include "ViewFinder.hpp"

int main()
{
  bool targetActive = false;
  sf::RenderWindow window(sf::VideoMode(1600, 900), "SFML works!");
  std::list<sf::Shape*> listDrawableElem;
  Planet planet(500, 500, 100);
  Player player(planet);
  ViewFinder *vFinder = NULL;

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
      } else if (event.type == sf::Event::MouseButtonPressed) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
          vFinder = new ViewFinder(event.mouseButton.x, event.mouseButton.y);
        }
      } else if (event.type == sf::Event::MouseMoved && vFinder) {
        vFinder->update(event.mouseMove.x, event.mouseMove.y);
      } else if (event.type == sf::Event::MouseButtonReleased) {
        delete vFinder;
        vFinder = NULL;
      }
     }

    window.clear();
    for (auto drawableElem: listDrawableElem) {
      window.draw(*drawableElem);
    }
    if (vFinder)
      window.draw(*vFinder);
    window.display();
  }
  return 0;
}
