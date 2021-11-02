#ifndef R_S_ROBOT_MOVEMENT_CONTROLLER_H
#define R_S_ROBOT_MOVEMENT_CONTROLLER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "../../object_collisions/robot/robot_collisions.h"
#include "../../models/robot/robot.h"
#include "../animations/robot_animations.h"
#include "../../constants.h"

class RobotMovementController {
private:
  Robot &robot;
  RobotAnimations &robotAnimations;
  RobotCollisions &robotCollisions;
  float velocityX = 0;
  float velocityY = 0;
  float accelerationY = 0.000005;
  float gravity = 0.00006;
  float maxYPosition = 352;
  bool jumpAfterIdle = false;
  bool jumpAfterTopCollision = false;
  bool reversedSprite = false;

  void run();

  void jump();

  void idle();

  void slide();

  void setNewRobotPosition(float x, float y);

  void setNewRobotMoveType(RobotMoveType type);

  void setNormalRobotParams();

  void setReversedRobotParams();

  bool isGroundElementCollision(float widthReduction, float heightReduction);

  bool isAirElementCollision(float widthReduction, float heightReduction);

public:
  RobotMovementController(
      Robot &robot,
      RobotAnimations &robotAnimations,
      RobotCollisions &robotCollisions
  ) : robot(robot), robotAnimations(robotAnimations), robotCollisions(robotCollisions) {}

  void keyController();

  void move();
};

#endif //R_S_ROBOT_MOVEMENT_CONTROLLER_H
