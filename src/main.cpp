#include <SFML/Graphics.hpp>
#include "constants.h"
#include "background/background.h"
#include "ground_generator/ground_generator.h"

int main() {
  sf::RenderWindow window(sf::VideoMode(constants::windowWidth, constants::windowHeight), "Run & Survive");
  Background bck(constants::windowWidth, window);
  GroundGenerator groundGenerator;
  bck.loadTexture();
  groundGenerator.load();

  while (window.isOpen()) {
    sf::Event event{};
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }
    window.clear();
    bck.draw();
    groundGenerator.draw(window);
    window.display();
    bck.move();
    groundGenerator.move();
  }

  return 0;
}

