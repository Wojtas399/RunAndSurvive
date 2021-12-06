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
      robot.moveType != RobotMoveType::fallDown &&
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
      shootClock.getElapsedTime().asMilliseconds() >= 350 &&
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
    case RobotMoveType::jump:
    case RobotMoveType::fallDown: {
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
      robotMovement.idle();
      break;
    }
    case RobotMoveType::slide: {
      robotMovement.slide(blockedSlide, velocityY, fallDownAfterSlide);
      break;
    }
  }
}

void RobotMovementController::moveUp() {
  velocityY = constants::robotVelocityY;
  accelerationY = 0.0001;
  robot.moveType = RobotMoveType::jump;
}

void RobotMovementController::moveDown() {
  if (
      !fallDownAfterSlide &&
      (robot.moveType == RobotMoveType::jump || robot.moveType == RobotMoveType::fallDown)
      ) {
    accelerationY = 0.0003;
  } else if (
      (robot.moveType == RobotMoveType::run || robot.moveType == RobotMoveType::idle) &&
      !robot.isReversed
      ) {
    robot.moveType = RobotMoveType::slide;
  }
}

void RobotMovementController::neitherMoveUpNorMoveDown() {
  if (robot.moveType == RobotMoveType::slide) {
    if (robotMovement.isAirElementCollision(26, 26, 17, 12)) {
      blockedSlide = true;
    } else {
      robot.moveType = RobotMoveType::run;
    }
  }
  fallDownAfterSlide = false;
}

void RobotMovementController::moveLeft() {
  velocityX = constants::robotLeftVelocityX;
  isFastRun = true;
  setReversedRobotParams();
}

void RobotMovementController::moveRight() {
  velocityX = constants::robotRightVelocityX;
  isFastRun = true;
  if (
      robot.moveType == RobotMoveType::slide &&
      !robotMovement.isAirElementCollision(24, 24, 17, 8)
      ) {
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
  if (!robot.isReversed && robot.moveType != RobotMoveType::slide) {
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
