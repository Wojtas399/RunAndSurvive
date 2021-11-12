#include "robot_movement_controller.h"

void RobotMovementController::keyController() {
  if (
      sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
      robot.moveType != RobotMoveType::jump &&
      robot.moveType != RobotMoveType::fallDown &&
      !robotMovement.isAirElementCollision(26, 26, 27, 12)
      ) {
    keyUp();
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
    keyDown();
  } else {
    neitherKeyUpNorKeyDown();
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    keyRight();
  } else if (
      sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&
      !robotMovement.isAirElementCollision(26, 26, 27, 8)
      ) {
    keyLeft();
  } else {
    neitherKeyLeftNorKeyRight();
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && robot.moveType == RobotMoveType::run) {
    keySpace();
  }
}

void RobotMovementController::move() {
  switch (robot.moveType) {
    case RobotMoveType::run: {
      robotMovement.run(velocityX, velocityY, isFastRun, isShoot);
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
      robotMovement.slide(blockedSlide, velocityY, fallDownAfterSlide, isShoot);
      break;
    }
  }
}

void RobotMovementController::keyUp() {
  velocityY = -0.08;
  accelerationY = 0.000005;
  isShoot = false;
  robot.moveType = RobotMoveType::jump;
}

void RobotMovementController::keyDown() {
  isShoot = false;
  if (
      !fallDownAfterSlide &&
      (robot.moveType == RobotMoveType::jump || robot.moveType == RobotMoveType::fallDown)
      ) {
    accelerationY = 0.00009;
  } else if (
      (robot.moveType == RobotMoveType::run || robot.moveType == RobotMoveType::idle) &&
      !robot.isReversed
      ) {
    robot.moveType = RobotMoveType::slide;
  }
}

void RobotMovementController::neitherKeyUpNorKeyDown() {
  if (robot.moveType == RobotMoveType::slide) {
    if (robotMovement.isAirElementCollision(26, 26, 17, 12)) {
      blockedSlide = true;
    } else {
      robot.moveType = RobotMoveType::run;
    }
  }
  fallDownAfterSlide = false;
}

void RobotMovementController::keyLeft() {
  velocityX = -0.06;
  isFastRun = true;
  setReversedRobotParams();
}

void RobotMovementController::keyRight() {
  velocityX = 0.015;
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

void RobotMovementController::neitherKeyLeftNorKeyRight() {
  velocityX = 0;
  isFastRun = false;
  setNormalRobotParams();
}

void RobotMovementController::keySpace() {
  if (!isShoot) {
    isShoot = true;
    shootController.shoot();
  }
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
