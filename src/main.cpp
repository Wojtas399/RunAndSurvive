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
#include "ui/points_service/points_service.h"
#include "ui/life_service/life_service.h"
#include "ui/zobie_points_service/zombie_points_service.h"

int main() {
  srand(time(NULL));

  sf::RenderWindow window(sf::VideoMode(constants::windowWidth, constants::windowHeight), "Run & Survive");
  sf::Clock mainClock;
  bool isMenuOpen = true;
  bool isInstructionOpen = false;

  //Global
  GameParams gameParams;
  LifeService lifeService;
  PointsService pointsService;
  ZombiePointsService zombiePointsService(gameParams);
  ButtonsService buttonsService;
  MenuService menuService(buttonsService);
  InstructionService instructionService(buttonsService);
  EndGameService endGameService(buttonsService);
  BonusService bonusService;
  UIController uiController(
      lifeService,
      pointsService,
      zombiePointsService,
      menuService,
      instructionService,
      endGameService,
      buttonsService,
      bonusService
  );
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
  RobotMovementController robotMovementController(
      gameParams,
      robot,
      robotCollisions,
      robotMovement,
      robotShootController
  );
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
      uiController,
      robot,
      mapGenerator,
      robotController,
      zombieController,
      bulletCollisions,
      robotZombieCollisions
  );
  globalController.loadTextures();

  while (window.isOpen()) {
    if (mainClock.getElapsedTime().asMilliseconds() > 10) {
      sf::Event event{};
      while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
          window.close();
        }
        if (gameParams.isGameStarted) {
          globalController.robotKeyController();
        } else if (event.type == sf::Event::KeyPressed) {
          if (isInstructionOpen) {
            globalController.instructionScreenKeyController(isMenuOpen, isInstructionOpen);
          } else if (isMenuOpen && event.type == sf::Event::KeyPressed) {
            globalController.menuScreenKeyController(window, isMenuOpen, isInstructionOpen);
          } else {
            globalController.endScreenKeyController(isMenuOpen);
          }
        }
      }

      if (robot.getPosition().x + robot.spriteWidth < 0 || lifeService.livesAmount == 0) {
        gameParams.isGameStarted = false;
      }

      if (gameParams.isGameStarted) {
        globalController.step();
      }

      window.clear();
      if (!gameParams.isGameStarted) {
        if (isMenuOpen) {
          globalController.displayMenu(window);
        } else if (isInstructionOpen) {
          globalController.displayInstruction(window);
        } else {
          globalController.displayResult(window);
        }
      } else {
        globalController.draw(window);
      }
      window.display();
      mainClock.restart();
    }
  }

  return 0;
}
