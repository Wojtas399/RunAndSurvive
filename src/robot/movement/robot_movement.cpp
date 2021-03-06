#include "robot_movement.h"

void RobotMovement::run(float &velocityX, float &velocityY, bool &isFastRun) {
  velocityY = 0;
  sf::Vector2<float> position = robot.getPosition();
  float x = position.x;
  float y = position.y;
  if (isCollisionForward(x, y, velocityX)) {
    robot.moveType = RobotMoveType::idle;
  } else {
    x += velocityX;
  }
  if (!isCollisionBottom(x, y, 4) && y < 532) {
    robot.moveType = RobotMoveType::jump;
    velocityY = 0.045;
  }
  robot.setPosition(x, y);
  if (robot.isShoot && canShoot()) {
    robotAnimations.runShootAnim(robot.sprite, isFastRun);
  } else {
    robotAnimations.runAnim(robot.sprite, isFastRun);
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
  sf::Vector2<float> position = robot.getPosition();
  float x = position.x;
  float y = position.y;

  if (
      velocityY < 0 &&
      isAirCollisionVertically(x, y, velocityY) &&
      (
          !isCollisionForward(x, y, velocityX) ||
          isAirCollisionVertically(x - 8, y, velocityY)
      )
      ) {
    velocityY = 0.1;
  }
  if (velocityY > 0 && isCollisionBottom(x + (robot.isReversed ? 10.0f : -10.0f), y, velocityY)) {
    verticalPositionCorrection(x, y, velocityY);
    robot.moveType = RobotMoveType::run;
    accelerationY = constants::robotAccelerationY;
  }
  if (isCollisionForward(x, y, velocityX)) {
    horizontalPositionCorrection(x, y, velocityX);
    velocityX = -gameParams.mapSpeed;
  }

  x += velocityX;
  y += velocityY;
  velocityY += accelerationY;

  if (robot.moveType == RobotMoveType::run) {
    maxYPosition = y - 80;
  }
  if (y < maxYPosition) {
    y += gravity;
  }
  if (y >= 532) {
    y = 532;
    maxYPosition = y - 80;
    robot.moveType = RobotMoveType::run;
  }

  robot.setPosition(x, y);
  robotAnimations.jumpAnim(robot.sprite, velocityY, maxYPosition);
}

void RobotMovement::idle(float &velocityY) {
  sf::Vector2<float> position = robot.getPosition();
  float x = position.x;
  float y = position.y;
  float translationX = robot.isReversed ? -5.0f : 5.0f;
  x -= gameParams.mapSpeed;
  if (
      y < 532 &&
      velocityY > 0 &&
      isCollisionForward(x, y, translationX)
      ) {
    verticalPositionCorrection(x, y, velocityY);
    y = y + velocityY > 532 ? 532 : y + velocityY;
  }
  if (!isCollisionForward(x, y, robot.isReversed ? -4 : 4)) {
    robot.moveType = RobotMoveType::run;
  }
  robot.setPosition(x, y);
  if (robot.isShoot && canShoot()) {
    robotAnimations.shootAnim(robot.sprite);
  } else {
    robotAnimations.idleAnim(robot.sprite);
  }
}

void RobotMovement::slide(float &velocityX) {
  sf::Vector2<float> position = robot.getPosition();
  float x = position.x + (robot.isReversed ? velocityX + 0.5f : 0);
  robot.setPosition(x, position.y);
  robotAnimations.slideAnim(robot.sprite);
}

bool RobotMovement::isCollisionForward(float x, float y, float translationX) {
  return isGroundCollisionForward(x, y, translationX) || isAirCollisionForward(x, y, translationX);
}

bool RobotMovement::isCollisionBottom(float x, float y, float translationY) {
  return isGroundCollisionBottom(x, y, translationY) || isAirCollisionVertically(x, y, translationY);
}

bool RobotMovement::isGroundCollisionForward(float x, float y, float translationX) {
  return collisions.isCollisionWithGroundElement(x + translationX, y);
}

bool RobotMovement::isGroundCollisionBottom(float x, float y, float translationY) {
  return collisions.isCollisionWithGroundElement(x, y + translationY);
}

bool RobotMovement::isAirCollisionForward(float x, float y, float translationX) {
  return collisions.isCollisionWithAirElement(x + translationX, y, 10);
}

bool RobotMovement::isAirCollisionVertically(float x, float y, float translationY) {
  return collisions.isCollisionWithAirElement(x, y + translationY, 10);
}

void RobotMovement::horizontalPositionCorrection(float &x, float y, float translationX) {
  float counter = robot.isReversed ? 0.5 : -0.5;
  while (isCollisionForward(x, y, translationX)) {
    x += counter;
  }
}

void RobotMovement::verticalPositionCorrection(float x, float y, float &translationY) {
  float helper = !isCollisionForward(x, y, 4)
                 ? 0
                 : robot.isReversed ? 5.0f : -5.0f;
  while (isCollisionBottom(x + helper, y, translationY)) {
    translationY -= 0.5;
  }
}

bool RobotMovement::canShoot() {
  sf::Vector2<float> position = robot.getPosition();
  float x = position.x;
  float y = position.y;
  float translationX = robot.isReversed ? -5.0f : 5.0f;
  return !isGroundCollisionForward(x, y, translationX) &&
         !collisions.isCollisionWithAirElement(x + translationX, y, 18);
}
