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
      bool &jumpAfterIdle,
      bool &jumpAfterTopCollision,
      float &maxYPosition,
      float &gravity
  );

  void stopMovementVertically(float &y, float &velocityY, float &maxYPosition);

public:
  RobotMovement(
      Robot &robot,
      RobotAnimations &robotAnimations,
      RobotCollisions &robotCollisions
  ) : robot(robot), robotAnimations(robotAnimations), robotCollisions(robotCollisions) {}

  void run(float &velocityX, float &velocityY);

  void jump(
      float &velocityX,
      float &velocityY,
      float &accelerationY,
      float &maxYPosition,
      float &gravity,
      bool &jumpAfterIdle,
      bool &jumpAfterTopCollision
  );

  void idle();

  void slide(bool &blockedSlide, float &velocityY, bool &fallDownAfterSlide);

  bool isGroundElementCollision(float widthReduction, float heightReduction);

  bool isAirElementCollision(float widthReduction, float topReduction, float bottomReduction);
};

#endif //R_S_ROBOT_MOVEMENT_H
