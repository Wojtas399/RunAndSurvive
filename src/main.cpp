#include <SFML/Graphics.hpp>
#include "iostream"
#include "constants.h"
#include "map/generators/background/background_generator.h"
#include "map/generators/ground_elements/ground_elements_generator.h"
#include "map/generators/air_elements/air_elements_generator.h"
#include "map/generators/map/map_generator.h"
#include "object_collisions/robot/robot_collisions.h"
#include "robot/robot_controller.h"
#include "zombie/textures/zombie_textures.h"
#include "zombie/zombie_controller.h"
#include "global_controller/global_controller.h"
#include "life_service/life_service.h"

int main() {
  srand(time(NULL));

  sf::RenderWindow window(sf::VideoMode(constants::windowWidth, constants::windowHeight), "Run & Survive");
  sf::Clock mainClock;

  //Global
  GameParams gameParams;
  PointsService pointsService;
  LifeService lifeService;
  //Map
  BackgroundGenerator backgroundGenerator(gameParams);
  GroundElementsGenerator groundElementsGenerator(gameParams);
  AirElementsGenerator airElementsGenerator(gameParams);
  MapGenerator mapGenerator(gameParams, backgroundGenerator, groundElementsGenerator, airElementsGenerator);
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
  RobotMovement robotMovement(gameParams, robot, robotAnimations, robotCollisions);
  RobotShootController robotShootController(gameParams, robot, robotTextures, bulletCollisions);
  RobotMovementController robotMovementController(gameParams, robot, robotCollisions, robotMovement, robotShootController);
  RobotController robotController(robot, robotAnimations, robotMovementController, robotShootController);
  //Zombie
  ZombieTextures zombieTextures;
  ZombieAnimations zombieAnimations(zombieTextures, lifeService);
  ZombieCollisions zombieCollisions(mapElementsCollisions);
  ZombieMovementController zombieMovementController(gameParams, zombieAnimations, zombieCollisions);
  ZombieController zombieController(gameParams, zombieMovementController);

  RobotZombieCollisions robotZombieCollisions;
  GlobalController globalController(
      gameParams,
      pointsService,
      lifeService,
      robot,
      mapGenerator,
      robotController,
      zombieController,
      bulletCollisions,
      robotZombieCollisions
  );
  globalController.loadTextures();

  bool isGameStarted = false;

  while (window.isOpen()) {
    if (mainClock.getElapsedTime().asMilliseconds() > 10) {
      sf::Event event{};
      while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
          window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !isGameStarted) {
          isGameStarted = true;
          globalController.resetClock();
        }
        robotController.keyController();
      }

      if (robot.getPosition().x + robot.spriteWidth < 0 || lifeService.lifeAmount == 0) {
        window.close();
      }

      if (isGameStarted) {
        globalController.step();
      }

      window.clear();
      globalController.draw(window);
      window.display();
      mainClock.restart();
    }
  }

  return 0;
}
