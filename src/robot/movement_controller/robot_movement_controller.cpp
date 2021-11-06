#include "robot_movement_controller.h"

void RobotMovementController::keyController() {
  if (
      sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
      robot.moveType != RobotMoveType::jump &&
      robot.moveType != RobotMoveType::fallDown &&
      !robotMovement.isAirElementCollision(26, 27, 12)
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
      !robotMovement.isAirElementCollision(26, 27, 8)
      ) {
    keyLeft();
  } else {
    neitherKeyLeftNorKeyRight();
  }
}

void RobotMovementController::move() {
  switch (robot.moveType) {
    case RobotMoveType::run: {
      robotMovement.run(velocityX, velocityY);
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
          jumpAfterIdle,
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

void RobotMovementController::keyUp() {
  if (robot.moveType == RobotMoveType::idle) {
    jumpAfterIdle = true;
  }
  velocityY = -0.08;
  accelerationY = 0.000005;
  robot.moveType = RobotMoveType::jump;
}

void RobotMovementController::keyDown() {
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
    if (robotMovement.isAirElementCollision(26, 17, 12)) {
      blockedSlide = true;
    } else {
      robot.moveType = RobotMoveType::run;
    }
  }
  fallDownAfterSlide = false;
}

void RobotMovementController::keyLeft() {
  velocityX = -0.06;
  setReversedRobotParams();
}

void RobotMovementController::keyRight() {
  velocityX = 0.015;
  if (
      robot.moveType == RobotMoveType::slide &&
      !robotMovement.isAirElementCollision(24, 17, 8)
      ) {
    robot.moveType = RobotMoveType::run;
  } else {
    setNormalRobotParams();
  }
}

void RobotMovementController::neitherKeyLeftNorKeyRight() {
  velocityX = 0;
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
    std::cout << "?\n";
    robot.sprite.setPosition(robot.getPosition().x - robot.spriteWidth, robot.getPosition().y);
    robot.sprite.setScale(constants::robotScale, constants::robotScale);
  }
}
