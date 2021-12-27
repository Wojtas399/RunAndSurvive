#include "robot_movement_controller.h"

void RobotMovementController::move(
    bool isKeyUpPressed,
    bool isKeyDownPressed,
    bool isKeyLeftPressed,
    bool isKeyRightPressed,
    bool isSpacePressed
) {
  verticalMovement(isKeyUpPressed, isKeyDownPressed);
  horizontalMovement(isKeyLeftPressed, isKeyRightPressed);
  shootMovement(isSpacePressed);
  doMatchingMovement();
}

void RobotMovementController::verticalMovement(bool isKeyUpPressed, bool isKeyDownPressed) {
  if (
      isKeyUpPressed &&
      robot.moveType != RobotMoveType::jump &&
      robot.moveType != RobotMoveType::slide
      ) {
    moveUp();
  } else if (isKeyDownPressed) {
    moveDown();
  } else {
    neitherMoveUpNorMoveDown();
  }
}

void RobotMovementController::horizontalMovement(bool isKeyLeftPressed, bool isKeyRightPressed) {
  if (isKeyLeftPressed) {
    moveLeft();
  } else if (isKeyRightPressed) {
    moveRight();
  } else {
    neitherMoveLeftNorMoveRight();
  }
}

void RobotMovementController::shootMovement(bool isSpacePressed) {
  if (
      isSpacePressed &&
      shootClock.getElapsedTime().asMilliseconds() >= 250 &&
      (
          robot.moveType == RobotMoveType::run ||
          robot.moveType == RobotMoveType::idle
      )
      ) {
    robot.isShoot = true;
    shootController.shoot();
    shootClock.restart();
  } else if (!isSpacePressed) {
    robot.isShoot = false;
  }
}

void RobotMovementController::doMatchingMovement() {
  switch (robot.moveType) {
    case RobotMoveType::run: {
      robotMovement.run(velocityX, velocityY, isFastRun);
      break;
    }
    case RobotMoveType::jump: {
      robotMovement.jump(
          velocityX,
          velocityY,
          accelerationY,
          maxYPosition,
          gravity,
          jumpAfterTopCollision
      );
      break;
    }
    case RobotMoveType::idle: {
      robotMovement.idle(velocityY);
      break;
    }
    case RobotMoveType::slide: {
      robotMovement.slide(velocityX);
      break;
    }
  }
}

void RobotMovementController::moveUp() {
  velocityY = constants::robotVelocityY;
  accelerationY = constants::robotAccelerationY;
  robot.moveType = RobotMoveType::jump;
}

void RobotMovementController::moveDown() {
  sf::Vector2<float> position = robot.getPosition();
  if (isCollisionForward(10)) {
    if (!isCollisionForward(18)) {
      robot.moveType = RobotMoveType::slide;
    } else {
      robot.moveType = RobotMoveType::idle;
    }
  } else if (robot.moveType == RobotMoveType::jump) {
    accelerationY = 0.7;
  } else if (position.y < 432 && !isCollisionBottom()) {
    velocityY = 0.045;
    robot.moveType = RobotMoveType::jump;
    maxYPosition = position.y;
  } else if (robot.moveType == RobotMoveType::run || robot.moveType == RobotMoveType::idle) {
    robot.moveType = RobotMoveType::slide;
  }
}

void RobotMovementController::neitherMoveUpNorMoveDown() {
  if (robot.moveType == RobotMoveType::slide && !isCollisionAtTheTop()) {
    robot.moveType = RobotMoveType::run;
  }
}

void RobotMovementController::moveLeft() {
  velocityX = gameParams.robotLeftVelocityX;
  isFastRun = true;
  setReversedRobotParams();
}

void RobotMovementController::moveRight() {
  velocityX = robot.getPosition().x + (robot.spriteWidth - 20) > constants::windowWidth
      ? 0
      : constants::robotRightVelocityX;
  isFastRun = true;
  if (robot.moveType == RobotMoveType::slide && !isCollisionAtTheTop()) {
    robot.moveType = RobotMoveType::run;
  } else {
    setNormalRobotParams();
  }
}

void RobotMovementController::neitherMoveLeftNorMoveRight() {
  velocityX = 0;
  isFastRun = false;
  setNormalRobotParams();
}

void RobotMovementController::setReversedRobotParams() {
  if (!robot.isReversed) {
    robot.isReversed = true;
    robot.sprite.setPosition((robot.getPosition().x - 3) + robot.spriteWidth, robot.getPosition().y);
    robot.sprite.setScale(-constants::robotScale, constants::robotScale);
  }
}

void RobotMovementController::setNormalRobotParams() {
  if (robot.isReversed) {
    robot.isReversed = false;
    robot.sprite.setPosition(robot.getPosition().x - robot.spriteWidth, robot.getPosition().y);
    robot.sprite.setScale(constants::robotScale, constants::robotScale);
  }
}

bool RobotMovementController::isCollisionForward(float topReduction) {
  sf::Vector2<float> position = robot.getPosition();
  return collisions.isCollisionWithGroundElement(position.x + velocityX, position.y) ||
         collisions.isCollisionWithAirElement(position.x + velocityX, position.y, topReduction);
}

bool RobotMovementController::isCollisionBottom() {
  sf::Vector2<float> position = robot.getPosition();
  float x = position.x + (robot.isReversed ? 10.0f : -10.0f);
  return collisions.isCollisionWithGroundElement(x, position.y + 5) ||
         collisions.isCollisionWithAirElement(x, position.y + 5, 10);
}

bool RobotMovementController::isCollisionAtTheTop() {
  sf::Vector2<float> position = robot.getPosition();
  return collisions.isCollisionWithAirElement(position.x, position.y - 5, 10);
}
