#include <SFML/Graphics.hpp>
#include <list>
#include <unistd.h>
#include "game_conf.hpp"
#include "Univairse.hpp"

int main()
{
  sf::RenderWindow        window(sf::VideoMode(1600, 900), "SFML works!");
  const std::list<sf::Shape*>   *listDrawableElem;
  Univairse               univairse;

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      } else if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Left)
          univairse.playerMoveLeft();
        if (event.key.code == sf::Keyboard::Right)
          univairse.playerMoveRight();
      } else if (event.type == sf::Event::MouseButtonPressed) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
          univairse.playerActiveViewFinder(event.mouseButton.x, event.mouseButton.y);
        }
      } else if (event.type == sf::Event::MouseMoved && univairse.isViewFinderActive()) {
        univairse.playerUpdateViewFinder(event.mouseMove.x, event.mouseMove.y);
      } else if (event.type == sf::Event::MouseButtonReleased) {
        univairse.playerShoot();
      }
    }
    do {
      univairse.updateArrow();
      window.clear();
      listDrawableElem = univairse.getDrawableObject();
      for (auto drawableElem: *listDrawableElem) {
        window.draw(*drawableElem);
      }
      window.display();
    } while (univairse.isArrowAlive());
    delete listDrawableElem;
  }
  return 0;
}
