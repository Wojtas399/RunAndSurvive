#ifndef R_S_ROBOT_CONTROLLER_H
#define R_S_ROBOT_CONTROLLER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "../robot_animations/robot_animations.h"
#include "../../enums.h"

class RobotController {
private:
  float velocityY = 0;
  float gravity = 0.04;
  float maxYPosition = 312;
  enums::RobotMoveType &moveType;
  sf::Sprite &robot;

  void jump(int &jumpSpriteNumber);

  void setNewJumpSpriteNumber(int &jumpSpriteNumber);

public:
  RobotController(
      enums::RobotMoveType &moveType,
      sf::Sprite &robot
  ) : moveType(moveType), robot(robot) {}

  void keyController(sf::Event &event, int &jumpSpriteNumber);

  void move(int &jumpSpriteNumber);
};


#endif //R_S_ROBOT_CONTROLLER_H
