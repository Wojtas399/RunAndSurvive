#ifndef R_S_ROBOT_MOVEMENT_H
#define R_S_ROBOT_MOVEMENT_H

#include "../animations/robot_animations.h"
#include "../../object_collisions/robot/robot_collisions.h"

class RobotMovement {
private:
  Robot &robot;
  RobotAnimations &robotAnimations;
  RobotCollisions &robotCollisions;

  void jumpCollision(
      float &x,
      float &y,
      float &velocityX,
      float &velocityY,
      bool &jumpAfterTopCollision,
      float &maxYPosition,
      float &gravity
  );

  void setNewRobotPosition(float x, float y);

  void stopMovementVertically(float &y, float &velocityY, float &maxYPosition);

  void setFallDownMovement(float &velocityY);

  bool isNormalGroundCollision();

  bool isNormalAirCollision();

  bool isCollisionForward();

  bool isFreeSpaceUnder();

public:
  RobotMovement(
      Robot &robot,
      RobotAnimations &robotAnimations,
      RobotCollisions &robotCollisions
  ) : robot(robot), robotAnimations(robotAnimations), robotCollisions(robotCollisions) {}

  void run(float &velocityX, float &velocityY, bool &isFastRun);

  void jump(
      float &velocityX,
      float &velocityY,
      float &accelerationY,
      float &maxYPosition,
      float &gravity,
      bool &jumpAfterTopCollision
  );

  void idle();

  void slide(bool &blockedSlide, float &velocityY, bool &fallDownAfterSlide);

  bool isGroundElementCollision(float leftReduction, float rightReduction, float heightReduction);

  bool isAirElementCollision(float leftReduction, float rightReduction, float topReduction, float bottomReduction);
};

#endif //R_S_ROBOT_MOVEMENT_H
