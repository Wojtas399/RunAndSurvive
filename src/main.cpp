#include <SFML/Graphics.hpp>
#include "constants.h"
#include "background/background.h"

int main() {
  sf::RenderWindow window(sf::VideoMode(constants::windowWidth, constants::windowHeight), "Run & Survive");
  Background bck(constants::windowWidth, window);
  bck.loadTexture();

  while (window.isOpen()) {
    sf::Event event{};
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }
    window.clear();
    bck.draw();
    window.display();
    bck.move();
  }

  return 0;
}

