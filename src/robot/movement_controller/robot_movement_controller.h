#ifndef R_S_ROBOT_MOVEMENT_CONTROLLER_H
#define R_S_ROBOT_MOVEMENT_CONTROLLER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "../movement/robot_movement.h"
#include "../shoot_controller/robot_shoot_controller.h"

class RobotMovementController {
private:
  GameParams &gameParams;
  Robot &robot;
  RobotCollisions &collisions;
  RobotMovement &robotMovement;
  RobotShootController &shootController;
  float velocityX = 0;
  float velocityY = 0;
  float accelerationY = 0;
  float gravity = 0.00006;
  float maxYPosition = 452;
  bool isFastRun = false;
  bool jumpAfterTopCollision = false;
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

  bool isCollisionForward(float topReduction);

  bool isCollisionBottom();

  bool isCollisionAtTheTop();

public:
  RobotMovementController(
      GameParams &gameParams,
      Robot &robot,
      RobotCollisions &robotCollisions,
      RobotMovement &robotMovement,
      RobotShootController &robotShootController
  ) : gameParams(gameParams),
      robot(robot),
      collisions(robotCollisions),
      robotMovement(robotMovement),
      shootController(robotShootController) {}

  void move(
      bool isKeyUpPressed,
      bool isKeyDownPressed,
      bool isKeyLeftPressed,
      bool isKeyRightPressed,
      bool isSpacePressed
  );
};

#endif //R_S_ROBOT_MOVEMENT_CONTROLLER_H
