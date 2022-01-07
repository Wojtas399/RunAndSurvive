#ifndef R_S_ROBOT_SHOOT_CONTROLLER_H
#define R_S_ROBOT_SHOOT_CONTROLLER_H

#include <vector>
#include "../../models/bullet/bullet.h"
#include "../../models/robot/robot.h"
#include "../textures/robot_textures.h"
#include "../../object_collisions/bullet/bullet_collisions.h"
#include "../../game_params/game_params.h"
#include <iostream>

class RobotShootController {
  GameParams &gameParams;
  Robot &robot;
  RobotTextures &robotTextures;
  BulletCollisions &bulletCollisions;

  void movementController(Bullet &bullet, int bulletIndex);

  void setNewBulletParams(Bullet &bullet, int bulletIndex);

  void setNewBulletPosition(Bullet &bullet);

  void muzzleAnim(Bullet &bullet, int &bulletIndex);

  static void startMuzzleAnim(Bullet &bullet);

  static void setBulletOrientation(Bullet &bullet, sf::Vector2<float> scale);

  void setNextBulletTexture(Bullet &bullet);

  bool isCollisionWithMapElement(Bullet &bullet);

public:
  RobotShootController(
      GameParams &gameParams,
      Robot &robot,
      RobotTextures &robotTextures,
      BulletCollisions &bulletCollisions
      ): gameParams(gameParams), robot(robot), robotTextures(robotTextures), bulletCollisions(bulletCollisions) {}

  std::vector<Bullet> allBullets;

  void draw(sf::RenderWindow &window);

  void move();

  void shoot();
};

#endif //R_S_ROBOT_SHOOT_CONTROLLER_H
