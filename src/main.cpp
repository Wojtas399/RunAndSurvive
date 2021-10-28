#include <SFML/Graphics.hpp>
#include "constants.h"
#include "map/generators/background/background_generator.h"
#include "map/generators/ground_elements/ground_elements_generator.h"
#include "map/generators/air_elements/air_elements_generator.h"
#include "map/generators/map/map_generator.h"
#include "robot/robot.h"

int main() {
  srand(time(NULL));

  sf::RenderWindow window(sf::VideoMode(constants::windowWidth, constants::windowHeight), "Run & Survive");
  //Map
  BackgroundGenerator backgroundGenerator;
  GroundElementsGenerator groundElementsGenerator;
  AirElementsGenerator airElementsGenerator;
  MapGenerator mapGenerator(backgroundGenerator, groundElementsGenerator, airElementsGenerator);
  //Robot
  sf::Sprite robotSpr;
  enums::RobotMoveType moveType = enums::RobotMoveType::run;
  RobotAnimations robotAnimations;
  RobotController robotController(moveType, robotSpr);
  Robot robot(robotSpr, moveType, robotAnimations, robotController);

  mapGenerator.load();
  robot.load();

  while (window.isOpen()) {
    sf::Event event{};
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
      robot.movementController(event);
    }

    //movement
    mapGenerator.move();
    robot.move();

    //drawing
    window.clear();
    mapGenerator.draw(window);
    robot.draw(window);
    window.display();
  }

  return 0;
}
