#ifndef R_S_GLOBAL_CONTROLLER_H
#define R_S_GLOBAL_CONTROLLER_H


#include <SFML/Graphics.hpp>
#include <iostream>
#include "../map/generators/map/map_generator.h"
#include "../robot/robot_controller.h"
#include "../zombie/zombie_controller.h"

class GlobalController {
private:
  MapGenerator &mapGenerator;
  RobotController &robotController;
  ZombieController &zombieController;
  BulletCollisions &bulletCollisions;

  void setBulletExplosionPosition(Bullet &bullet, Zombie &zombie);
public:
  GlobalController(
      MapGenerator &mapGenerator,
      RobotController &robotController,
      ZombieController &zombieController,
      BulletCollisions &bulletCollisions
  ) : mapGenerator(mapGenerator),
      robotController(robotController),
      zombieController(zombieController),
      bulletCollisions(bulletCollisions) {}

  void loadTextures();

  void moveElements();

  void draw(sf::RenderWindow &window);
};


#endif //R_S_GLOBAL_CONTROLLER_H
