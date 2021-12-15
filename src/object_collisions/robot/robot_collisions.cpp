#include "robot_collisions.h"

bool RobotCollisions::isCollisionWithGroundElement(float x, float y) {
  return mapElementsCollisions.isCollisionWithGroundElement(
      x,
      y,
      robot.spriteWidth,
      robot.spriteHeight,
      robot.isReversed,
      24,
      24,
      8
  );
}

bool RobotCollisions::isCollisionWithAirElement(float x, float y) {
  return mapElementsCollisions.isCollisionWithAirElement(
      x,
      y,
      robot.spriteWidth,
      robot.spriteHeight,
      robot.isReversed,
      24,
      24,
      10,
      8
  );
}
