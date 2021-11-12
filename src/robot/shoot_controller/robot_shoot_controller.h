#ifndef R_S_ROBOT_SHOOT_CONTROLLER_H
#define R_S_ROBOT_SHOOT_CONTROLLER_H

#include <vector>
#include "../../models/bullet/bullet.h"
#include "../../models/robot/robot.h"
#include "../textures/robot_textures.h"
#include <iostream>

class RobotShootController {
  Robot &robot;
  RobotTextures &robotTextures;

  void setNewBulletParams(Bullet &bullet, int bulletIndex);

public:
  RobotShootController(
      Robot &robot,
      RobotTextures &robotTextures
      ): robot(robot), robotTextures(robotTextures) {}

  std::vector<Bullet> allBullets;

  void draw(sf::RenderWindow &window);

  void move();

  void shoot();
};

#endif //R_S_ROBOT_SHOOT_CONTROLLER_H
