#ifndef R_S_ROBOT_MOVEMENT_CONTROLLER_H
#define R_S_ROBOT_MOVEMENT_CONTROLLER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "../movement/robot_movement.h"
#include "../shoot_controller/robot_shoot_controller.h"

class RobotMovementController {
private:
  Robot &robot;
  RobotMovement &robotMovement;
  RobotShootController &shootController;
  float velocityX = 0;
  float velocityY = 0;
  float accelerationY = 0;
  float gravity = 0.00006;
  float maxYPosition = 352;
  bool isFastRun = false;
  bool jumpAfterTopCollision = false;
  bool fallDownAfterSlide = false;
  bool blockedSlide = false;
  sf::Clock shootClock;

  void verticalMovement(bool isKeyUpPressed, bool isKeyDownPressed);

  void horizontalMovement(bool isKeyLeftPressed, bool isKeyRightPressed);

  void shootMovement(bool isSpacePressed);

  void doMatchingMovement();

  void moveUp();

  void moveDown();

  void neitherMoveUpNorMoveDown();

  void moveLeft();

  void moveRight();

  void neitherMoveLeftNorMoveRight();

  void setReversedRobotParams();

  void setNormalRobotParams();

public:
  RobotMovementController(
      Robot &robot,
      RobotMovement &robotMovement,
      RobotShootController &robotShootController
  ) : robot(robot), robotMovement(robotMovement), shootController(robotShootController) {}

  void move(
      bool isKeyUpPressed,
      bool isKeyDownPressed,
      bool isKeyLeftPressed,
      bool isKeyRightPressed,
      bool isSpacePressed
  );
};

#endif //R_S_ROBOT_MOVEMENT_CONTROLLER_H
