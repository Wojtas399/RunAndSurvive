#ifndef R_S_ROBOT_MOVEMENT_H
#define R_S_ROBOT_MOVEMENT_H

#include "../animations/robot_animations.h"
#include "../../object_collisions/robot/robot_collisions.h"
#include "../../game_params/game_params.h"

class RobotMovement {
private:
  GameParams &gameParams;
  Robot &robot;
  RobotAnimations &robotAnimations;
  RobotCollisions &collisions;

  bool isCollisionForward(float x, float y, float translationX);

  bool isCollisionBottom(float x, float y, float translationY);

  bool isGroundCollisionForward(float x, float y, float translationX);

  bool isGroundCollisionBottom(float x, float y, float translationY);

  bool isAirCollisionForward(float x, float y, float translationX);

  bool isAirCollisionVertically(float x, float y, float translationY);

  void horizontalPositionCorrection(float &x, float y, float translationX);

  void verticalPositionCorrection(float x, float y, float &translationY);

  bool canShoot();

public:
  RobotMovement(
      GameParams &gameParams,
      Robot &robot,
      RobotAnimations &robotAnimations,
      RobotCollisions &robotCollisions
  ) : gameParams(gameParams), robot(robot), robotAnimations(robotAnimations), collisions(robotCollisions) {}

  void run(float &velocityX, float &velocityY, bool &isFastRun);

  void jump(
      float &velocityX,
      float &velocityY,
      float &accelerationY,
      float &maxYPosition,
      float &gravity,
      bool &jumpAfterTopCollision
  );

  void idle(float &velocityY);

  void slide(float &velocityX);
};

#endif //R_S_ROBOT_MOVEMENT_H
