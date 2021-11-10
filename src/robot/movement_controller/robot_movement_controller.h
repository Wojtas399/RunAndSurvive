#ifndef R_S_ROBOT_MOVEMENT_CONTROLLER_H
#define R_S_ROBOT_MOVEMENT_CONTROLLER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "../movement/robot_movement.h"

class RobotMovementController {
private:
  Robot &robot;
  RobotMovement &robotMovement;
  float velocityX = 0;
  float velocityY = 0;
  float accelerationY = 0.000005;
  float gravity = 0.00006;
  float maxYPosition = 352;
  bool isFastRun = false;
  bool jumpAfterTopCollision = false;
  bool fallDownAfterSlide = false;
  bool blockedSlide = false;

  void keyUp();

  void keyDown();

  void neitherKeyUpNorKeyDown();

  void keyLeft();

  void keyRight();

  void neitherKeyLeftNorKeyRight();

  void setReversedRobotParams();

  void setNormalRobotParams();

public:
  RobotMovementController(
      Robot &robot,
      RobotMovement &robotMovement
  ) : robot(robot), robotMovement(robotMovement) {}

  void keyController();

  void move();
};

#endif //R_S_ROBOT_MOVEMENT_CONTROLLER_H
