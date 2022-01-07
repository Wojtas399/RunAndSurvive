#ifndef R_S_GLOBAL_CONTROLLER_H
#define R_S_GLOBAL_CONTROLLER_H


#include <SFML/Graphics.hpp>
#include <iostream>
#include "../map/generators/map/map_generator.h"
#include "../robot/robot_controller.h"
#include "../zombie/zombie_controller.h"
#include "../object_collisions/robot_zombie/robot_zombie_collisions.h"
#include "../game_params/game_params.h"
#include "../ui/ui_controller.h"

class GlobalController {
private:
  GameParams &gameParams;
  UIController &uiController;
  Robot &robot;
  MapGenerator &mapGenerator;
  RobotController &robotController;
  ZombieController &zombieController;
  BulletCollisions &bulletCollisions;
  RobotZombieCollisions &robotZombieCollisions;
  sf::Clock gameClock;
  sf::Clock pointsClock;

  void moveElements();

  void checkCollisions();

  void setBulletExplosionPosition(Bullet &bullet, Zombie &zombie);

  void setZombieOrientation(Zombie &zombie);

  void updateGameParams();

public:
  GlobalController(
      GameParams &gameParams,
      UIController &uiController,
      Robot &robot,
      MapGenerator &mapGenerator,
      RobotController &robotController,
      ZombieController &zombieController,
      BulletCollisions &bulletCollisions,
      RobotZombieCollisions &robotZombieCollisions
  ) : gameParams(gameParams),
      uiController(uiController),
      robot(robot),
      mapGenerator(mapGenerator),
      robotController(robotController),
      zombieController(zombieController),
      bulletCollisions(bulletCollisions),
      robotZombieCollisions(robotZombieCollisions) {}

  void loadTextures();

  void step();

  void draw(sf::RenderWindow &window);

  void setInitialGameParams();
};


#endif //R_S_GLOBAL_CONTROLLER_H
