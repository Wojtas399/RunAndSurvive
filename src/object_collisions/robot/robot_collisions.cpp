#include "robot_collisions.h"

bool RobotCollisions::isCollisionWithGroundElement(
    float leftReduction,
    float rightReduction,
    float heightReduction
) {
  return mapElementsCollisions.isCollisionWithGroundElement(
      robot.getPosition().x,
      robot.getPosition().y,
      robot.spriteWidth,
      robot.spriteHeight,
      robot.isReversed,
      leftReduction,
      rightReduction,
      heightReduction
  );
}

bool RobotCollisions::isCollisionWithAirElement(
    float leftReduction,
    float rightReduction,
    float topReduction,
    float bottomReduction
) {
  return mapElementsCollisions.isCollisionWithAirElement(
      robot.getPosition().x,
      robot.getPosition().y,
      robot.spriteWidth,
      robot.spriteHeight,
      robot.isReversed,
      leftReduction,
      rightReduction,
      topReduction,
      bottomReduction
  );
}
