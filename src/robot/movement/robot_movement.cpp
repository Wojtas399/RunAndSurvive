#include "robot_movement.h"

void RobotMovement::run(float &velocityX, float &velocityY) {
  if (
      isGroundElementCollision(24, 8) ||
      isAirElementCollision(24, 8, 8)
      ) {
    robot.moveType = RobotMoveType::idle;
  } else if (
      !isGroundElementCollision(24, 4) &&
      !isAirElementCollision(24, 4, 4) &&
      robot.getPosition().y < 432
      ) {
    velocityY = 0.045;
    robot.moveType = RobotMoveType::fallDown;
  } else {
    if (robot.getPosition().x + (robot.spriteWidth - 24) > constants::windowWidth) {
      robot.sprite.setPosition(robot.getPosition().x - constants::mapSpeed, robot.getPosition().y);
    } else {
      robot.sprite.setPosition(robot.getPosition().x + velocityX, robot.getPosition().y);
    }
    robotAnimations.runAnim(robot.sprite, velocityX != 0);
  }
}

void RobotMovement::jump(
    float &velocityX,
    float &velocityY,
    float &accelerationY,
    float &maxYPosition,
    float &gravity,
    bool &jumpAfterIdle,
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
      jumpAfterIdle,
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
  if (!isAirElementCollision(24, 8, 8)) {
    jumpAfterTopCollision = false;
  }
  if (x + (robot.spriteWidth - 24) > constants::windowWidth) {
    robot.sprite.setPosition(x - constants::mapSpeed, y);
  } else {
    robot.sprite.setPosition(x, y);
  }
  if (robot.moveType == RobotMoveType::jump) {
    robotAnimations.jumpAnim(robot.sprite, velocityY, maxYPosition);
  } else if (robot.moveType == RobotMoveType::fallDown) {
    robotAnimations.jumpAnim(robot.sprite, velocityY, maxYPosition + 80);
  }
}

void RobotMovement::idle() {
  if (
      isGroundElementCollision(26, 8) ||
      isAirElementCollision(24, 8, 8)
      ) {
    sf::Vector2<float> robotPosition = robot.getPosition();
    robot.sprite.setPosition(robotPosition.x - constants::mapSpeed, robotPosition.y);
    robotAnimations.idleAnim(robot.sprite);
  } else {
    robot.moveType = RobotMoveType::run;
  }
}

void RobotMovement::slide(bool &blockedSlide, float &velocityY, bool &fallDownAfterSlide) {
  if (blockedSlide) {
    if (!isAirElementCollision(22, 17, 12)) {
      robot.moveType = RobotMoveType::run;
      blockedSlide = false;
    }
  } else {
    if (isGroundElementCollision(24, 8) || isAirElementCollision(24, 19, 8)) {
      robot.moveType = RobotMoveType::idle;
    } else if (
        !isGroundElementCollision(24, 4) &&
        !isAirElementCollision(24, 4, 4) &&
        robot.getPosition().y < 432
        ) {
      velocityY = 0.045;
      fallDownAfterSlide = true;
      robot.moveType = RobotMoveType::fallDown;
    } else {
      robotAnimations.slideAnim(robot.sprite);
    }
  }
}

bool RobotMovement::isGroundElementCollision(float widthReduction, float heightReduction) {
  return robotCollisions.isCollisionWithGroundElement(widthReduction, heightReduction);
}

bool RobotMovement::isAirElementCollision(
    float widthReduction,
    float topReduction,
    float bottomReduction
) {
  return robotCollisions.isCollisionWithAirElement(widthReduction, topReduction, bottomReduction);
}

void RobotMovement::jumpCollision(
    float &x,
    float &y,
    float &velocityX,
    float &velocityY,
    bool &jumpAfterIdle,
    bool &jumpAfterTopCollision,
    float &maxYPosition,
    float &gravity
) {
  if (isGroundElementCollision(24, 8) || isAirElementCollision(24, 8, 8)) {
    if (
        jumpAfterIdle ||
        (
            !isGroundElementCollision(26, 8) &&
            isGroundElementCollision(24, 8)
        ) ||
        (
            !isAirElementCollision(26, 8, 8) &&
            isAirElementCollision(24, 8, 8)
        )
        ) {
      if (isGroundElementCollision(24, 8) && isAirElementCollision(24, 8, 8)) {
        stopMovementVertically(y, velocityY, maxYPosition);
      } else {
        x -= constants::mapSpeed;
        velocityX = 0;
      }
    } else {
      if (velocityY < 0 && isAirElementCollision(24, 8, 8)) {
        velocityY = 0.03;
        jumpAfterTopCollision = true;
      } else if (!jumpAfterTopCollision) {
        stopMovementVertically(y, velocityY, maxYPosition);
      }
    }
  } else if (y < maxYPosition) {
    velocityY += gravity;
    jumpAfterIdle = false;
  }
}

void RobotMovement::stopMovementVertically(float &y, float &velocityY, float &maxYPosition) {
  y -= 2;
  velocityY = 0;
  robot.moveType = RobotMoveType::run;
  maxYPosition = y - 80;
}
