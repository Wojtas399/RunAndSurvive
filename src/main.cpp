#include <SFML/Graphics.hpp>
#include "constants.h"
#include "map/generators/background/background_generator.h"
#include "map/generators/ground_elements/ground_elements_generator.h"
#include "map/generators/air_elements/air_elements_generator.h"
#include "map/generators/map/map_generator.h"

int main() {
  srand(time(NULL));

  sf::RenderWindow window(sf::VideoMode(constants::windowWidth, constants::windowHeight), "Run & Survive");
  BackgroundGenerator backgroundGenerator;
  GroundElementsGenerator groundElementsGenerator;
  AirElementsGenerator airElementsGenerator;
  MapGenerator mapGenerator(backgroundGenerator, groundElementsGenerator, airElementsGenerator);

  mapGenerator.load();

  while (window.isOpen()) {
    sf::Event event{};
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }
    window.clear();
    mapGenerator.draw(window);
    window.display();
    mapGenerator.move();
  }

  return 0;
}
