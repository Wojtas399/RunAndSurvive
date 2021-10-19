#include <SFML/Graphics.hpp>
#include "constants.h"
#include "background/background.h"
#include "ground_generator/ground_generator.h"

int main() {
  std::random_device random_device;
  std::mt19937 random_engine(random_device());
  int maxElementsAmount = 2;

  sf::RenderWindow window(sf::VideoMode(constants::windowWidth, constants::windowHeight), "Run & Survive");
  Background bck(constants::windowWidth, window);
  AirElementsGenerator airElementsGenerator(window, random_engine);
  GroundElementsGenerator groundElementsGenerator(window, maxElementsAmount, random_engine);
  GroundGenerator groundGenerator(airElementsGenerator, groundElementsGenerator);

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

