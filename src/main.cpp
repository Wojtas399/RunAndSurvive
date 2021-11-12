#include <SFML/Graphics.hpp>
#include "constants.h"
#include "map/generators/background/background_generator.h"
#include "map/generators/ground_elements/ground_elements_generator.h"
#include "map/generators/air_elements/air_elements_generator.h"
#include "map/generators/map/map_generator.h"
#include "object_collisions/robot/robot_collisions.h"
#include "robot/robot_controller.h"

int main() {
  srand(time(NULL));

  sf::RenderWindow window(sf::VideoMode(constants::windowWidth, constants::windowHeight), "Run & Survive");
  //Map
  BackgroundGenerator backgroundGenerator;
  GroundElementsGenerator groundElementsGenerator;
  AirElementsGenerator airElementsGenerator;
  MapGenerator mapGenerator(backgroundGenerator, groundElementsGenerator, airElementsGenerator);
  MapElementsCollisions mapElementsCollisions(
      airElementsGenerator.airElements,
      groundElementsGenerator.groundElements
  );
  //Robot
  Robot robot;
  RobotTextures robotTextures;
  RobotAnimations robotAnimations(robotTextures);
  RobotCollisions robotCollisions(mapElementsCollisions, robot);
  BulletCollisions bulletCollisions(mapElementsCollisions);
  RobotMovement robotMovement(robot, robotAnimations, robotCollisions);
  RobotShootController robotShootController(robot, robotTextures, bulletCollisions);
  RobotMovementController robotMovementController(robot, robotMovement, robotShootController);
  RobotController robotController(robot, robotAnimations, robotMovementController, robotShootController);

  mapGenerator.load();
  robotController.loadTextures();

  while (window.isOpen()) {
    sf::Event event{};
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed || robot.getPosition().x + robot.spriteWidth < 0) {
        window.close();
      }
      robotController.eventController();
    }

    //movement
    mapGenerator.move();
    robotController.move();

    //drawing
    window.clear();
    mapGenerator.draw(window);
    robotController.draw(window);
    window.display();
  }

  return 0;
}
