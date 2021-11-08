#include "robot_movement.h"

void RobotMovement::run(float &velocityX, float &velocityY) {
  if (isNormalGroundCollision() || isNormalAirCollision()) {
    robot.moveType = RobotMoveType::idle;
  } else if (isFreeSpaceUnder()) {
    setFallDownMovement(velocityY);
  } else {
    setNewRobotPosition(robot.getPosition().x + velocityX, robot.getPosition().y);
    robotAnimations.runAnim(robot.sprite, velocityX != 0);
  }
}

void RobotMovement::jump(
    float &velocityX,
    float &velocityY,
    float &accelerationY,
    float &maxYPosition,
    float &gravity,
    bool &jumpAfterTopCollision
) {
  float x = robot.getPosition().x;
  float y = robot.getPosition().y;
  x += velocityX;
  y += velocityY;
  velocityY += accelerationY;
  jumpCollision(
      x,
      y,
      velocityX,
      velocityY,
      jumpAfterTopCollision,
      maxYPosition,
      gravity
  );
  if (y >= 432) {
    y = 432;
    if (robot.getPosition().y == 432) {
      robot.moveType = RobotMoveType::run;
    }
    maxYPosition = y - 80;
  }
  if (!isNormalAirCollision()) {
    jumpAfterTopCollision = false;
  }
  setNewRobotPosition(x, y);
  if (robot.moveType == RobotMoveType::jump) {
    robotAnimations.jumpAnim(robot.sprite, velocityY, maxYPosition);
  } else if (robot.moveType == RobotMoveType::fallDown) {
    robotAnimations.jumpAnim(robot.sprite, velocityY, maxYPosition + 80);
  }
}

void RobotMovement::idle() {
  if (isCollisionForward()) {
    sf::Vector2<float> robotPosition = robot.getPosition();
    setNewRobotPosition(robotPosition.x - constants::mapSpeed, robotPosition.y);
    robotAnimations.idleAnim(robot.sprite);
  } else {
    robot.moveType = RobotMoveType::run;
  }
}

void RobotMovement::slide(bool &blockedSlide, float &velocityY, bool &fallDownAfterSlide) {
  if (blockedSlide) {
    if (!isAirElementCollision(22, 22, 17, 12)) {
      robot.moveType = RobotMoveType::run;
      blockedSlide = false;
    }
  } else {
    if (isNormalGroundCollision() || isAirElementCollision(24, 24, 19, 8)) {
      robot.moveType = RobotMoveType::idle;
    } else if (isFreeSpaceUnder()) {
      setFallDownMovement(velocityY);
      fallDownAfterSlide = true;
    } else {
      robotAnimations.slideAnim(robot.sprite);
    }
  }
}

bool RobotMovement::isGroundElementCollision(float leftReduction, float rightReduction, float heightReduction) {
  return robotCollisions.isCollisionWithGroundElement(leftReduction, rightReduction, heightReduction);
}

bool RobotMovement::isAirElementCollision(
    float leftReduction,
    float rightReduction,
    float topReduction,
    float bottomReduction
) {
  return robotCollisions.isCollisionWithAirElement(leftReduction, rightReduction, topReduction, bottomReduction);
}

void RobotMovement::jumpCollision(
    float &x,
    float &y,
    float &velocityX,
    float &velocityY,
    bool &jumpAfterTopCollision,
    float &maxYPosition,
    float &gravity
) {
  if (isNormalGroundCollision() || isNormalAirCollision()) {
    if (
        (
            !isGroundElementCollision(26, 26, 8) &&
            isNormalGroundCollision()
        ) ||
        (
            !isAirElementCollision(26, 26, 8, 8) &&
            isNormalAirCollision()
        )
        ) {
      if (isNormalGroundCollision() && isNormalAirCollision()) {
        stopMovementVertically(y, velocityY, maxYPosition);
      } else {
        if (isCollisionForward()) {
          x -= constants::mapSpeed;
          velocityX = 0;
        }
      }
    } else {
      if (velocityY < 0 && isNormalAirCollision()) {
        velocityY = 0.03;
        jumpAfterTopCollision = true;
      } else if (!jumpAfterTopCollision) {
        stopMovementVertically(y, velocityY, maxYPosition);
      }
    }
  } else if (y < maxYPosition) {
    velocityY += gravity;
  }
}

void RobotMovement::setNewRobotPosition(float x, float y) {
  if (x + (robot.spriteWidth - 24) > constants::windowWidth) {
    robot.sprite.setPosition(x - constants::mapSpeed, y);
  } else {
    robot.sprite.setPosition(x, y);
  }
}

void RobotMovement::stopMovementVertically(float &y, float &velocityY, float &maxYPosition) {
  y -= 2;
  velocityY = 0;
  robot.moveType = RobotMoveType::run;
  maxYPosition = y - 80;
}

void RobotMovement::setFallDownMovement(float &velocityY) {
  velocityY = 0.045;
  robot.moveType = RobotMoveType::fallDown;
}

bool RobotMovement::isNormalGroundCollision() {
  return isGroundElementCollision(24, 24, 8);
}

bool RobotMovement::isNormalAirCollision() {
  return isAirElementCollision(24, 24, 8, 8);
}

bool RobotMovement::isCollisionForward() {
  if (robot.isReversed) {
    return isGroundElementCollision(24, 26, 8) ||
           isAirElementCollision(24, 26, 8, 8);
  } else {
    return isGroundElementCollision(26, 24, 8) ||
           isAirElementCollision(26, 24, 8, 8);
  }
}

bool RobotMovement::isFreeSpaceUnder() {
  return !isGroundElementCollision(24, 24, 4) &&
         !isAirElementCollision(24, 24, 4, 4) &&
         robot.getPosition().y < 432;
}
