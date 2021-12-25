#ifndef R_S_GLOBAL_CONTROLLER_H
#define R_S_GLOBAL_CONTROLLER_H


#include <SFML/Graphics.hpp>
#include <iostream>
#include "../map/generators/map/map_generator.h"
#include "../robot/robot_controller.h"
#include "../zombie/zombie_controller.h"
#include "../object_collisions/robot_zombie/robot_zombie_collisions.h"
#include "../points_service/points_service.h"
#include "../life_service/life_service.h"

class GlobalController {
private:
  PointsService &pointsService;
  LifeService &lifeService;
  Robot &robot;
  MapGenerator &mapGenerator;
  RobotController &robotController;
  ZombieController &zombieController;
  BulletCollisions &bulletCollisions;
  RobotZombieCollisions &robotZombieCollisions;
  sf::Clock pointsClock;

  void moveElements();

  void checkCollisions();

  void setBulletExplosionPosition(Bullet &bullet, Zombie &zombie);

  void setZombieOrientation(Zombie &zombie);

public:
  GlobalController(
      PointsService &pointsService,
      LifeService &lifeService,
      Robot &robot,
      MapGenerator &mapGenerator,
      RobotController &robotController,
      ZombieController &zombieController,
      BulletCollisions &bulletCollisions,
      RobotZombieCollisions &robotZombieCollisions
  ) : pointsService(pointsService),
      lifeService(lifeService),
      robot(robot),
      mapGenerator(mapGenerator),
      robotController(robotController),
      zombieController(zombieController),
      bulletCollisions(bulletCollisions),
      robotZombieCollisions(robotZombieCollisions) {}

  void loadTextures();

  void resetClock();

  void step();

  void draw(sf::RenderWindow &window);
};


#endif //R_S_GLOBAL_CONTROLLER_H
