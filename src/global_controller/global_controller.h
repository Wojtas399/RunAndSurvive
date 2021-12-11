#ifndef R_S_GLOBAL_CONTROLLER_H
#define R_S_GLOBAL_CONTROLLER_H


#include <SFML/Graphics.hpp>
#include <iostream>
#include "../map/generators/map/map_generator.h"
#include "../robot/robot_controller.h"
#include "../zombie/zombie_controller.h"
#include "../object_collisions/robot_zombie/robot_zombie_collisions.h"

class GlobalController {
private:
  Robot &robot;
  MapGenerator &mapGenerator;
  RobotController &robotController;
  ZombieController &zombieController;
  BulletCollisions &bulletCollisions;
  RobotZombieCollisions &robotZombieCollisions;

  void setBulletExplosionPosition(Bullet &bullet, Zombie &zombie);

public:
  GlobalController(
      Robot &robot,
      MapGenerator &mapGenerator,
      RobotController &robotController,
      ZombieController &zombieController,
      BulletCollisions &bulletCollisions,
      RobotZombieCollisions &robotZombieCollisions
  ) : robot(robot),
      mapGenerator(mapGenerator),
      robotController(robotController),
      zombieController(zombieController),
      bulletCollisions(bulletCollisions),
      robotZombieCollisions(robotZombieCollisions) {}

  void loadTextures();

  void moveElements();

  void draw(sf::RenderWindow &window);
};


#endif //R_S_GLOBAL_CONTROLLER_H
