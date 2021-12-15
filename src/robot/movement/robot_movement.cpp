#include "robot_movement.h"

void RobotMovement::run(float &velocityX, float &velocityY, bool &isFastRun) {
  sf::Vector2<float> position = robot.getPosition();
  float x = position.x;
  float y = position.y;
  if (isCollisionForward(x, y, velocityX)) {
    robot.moveType = RobotMoveType::idle;
  } else {
    x += velocityX;
  }
  if (!isCollisionBottom(x, y, 4) && y < 432) {
    robot.moveType = RobotMoveType::jump;
    velocityY = 0.045;
  }
  robot.setPosition(x, y);
  robotAnimations.runAnim(robot.sprite, isFastRun);
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
  }
  if (isCollisionForward(x, y, velocityX)) {
    horizontalPositionCorrection(x, y, velocityX);
    velocityX = -constants::mapSpeed;
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
  if (y >= 432) {
    y = 432;
    maxYPosition = y - 80;
    robot.moveType = RobotMoveType::run;
  }

  robot.setPosition(x, y);
  robotAnimations.jumpAnim(robot.sprite, velocityY, maxYPosition);
}

void RobotMovement::idle() {
  sf::Vector2<float> position = robot.getPosition();
  float x = position.x;
  float y = position.y;
  x -= constants::mapSpeed;
  if (robot.isReversed) {
    robot.moveType = RobotMoveType::run;
  }
  robot.setPosition(x, y);
  robotAnimations.idleAnim(robot.sprite);
}

void RobotMovement::slide(bool &blockedSlide, float &velocityY, bool &fallDownAfterSlide) {
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
  return collisions.isCollisionWithAirElement(x + translationX, y);
}

bool RobotMovement::isAirCollisionVertically(float x, float y, float translationY) {
  return collisions.isCollisionWithAirElement(x, y + translationY);
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
