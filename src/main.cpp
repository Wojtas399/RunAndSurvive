#include <SFML/Graphics.hpp>
#include "background/background.h"

int main() {
  int windowWidth = 1400;
  int windowHeight = 800;
  sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Run & Survive");
  Background bck(windowWidth, window);
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

