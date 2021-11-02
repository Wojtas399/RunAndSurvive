#include "robot_movement_controller.h"

void RobotMovementController::keyController() {
  if (
      sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
      robot.moveType != RobotMoveType::jump &&
      robot.moveType != RobotMoveType::fallDown
      ) {
    if (robot.moveType == RobotMoveType::idle) {
      jumpAfterIdle = true;
    }
    velocityY = -0.08;
    accelerationY = 0.000005;
    setNewRobotMoveType(RobotMoveType::jump);
  } else if (
      sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
      (robot.moveType == RobotMoveType::jump || robot.moveType == RobotMoveType::fallDown)
      ) {
    accelerationY = 0.00009;
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    velocityX = 0.015;
    setNormalRobotParams();
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    velocityX = -0.06;
    setReversedRobotParams();
  } else {
    velocityX = 0;
    setNormalRobotParams();
  }
}

void RobotMovementController::move() {
  switch (robot.moveType) {
    case RobotMoveType::run: {
      run();
      break;
    }
    case RobotMoveType::jump:
    case RobotMoveType::fallDown: {
      jump();
      break;
    }
    case RobotMoveType::idle: {
      idle();
      break;
    }
  }
}

void RobotMovementController::run() {
  if (isGroundElementCollision(24, 8) || isAirElementCollision(24, 8)) {
    setNewRobotMoveType(RobotMoveType::idle);
  } else if (
      !isGroundElementCollision(24, 4) &&
      !isAirElementCollision(24, 4) &&
      robot.getPosition().y < 432
      ) {
    velocityY = 0.045;
    setNewRobotMoveType(RobotMoveType::fallDown);
  } else {
    setNewRobotPosition(robot.getPosition().x + velocityX, robot.getPosition().y);
    robotAnimations.runAnim(robot.sprite);
  }
}

void RobotMovementController::jump() {
  float x = robot.getPosition().x;
  float y = robot.getPosition().y;
  x += velocityX;
  y += velocityY;
  velocityY += accelerationY;
  if (isGroundElementCollision(24, 8) || isAirElementCollision(24, 8)) {
    if (
        jumpAfterIdle ||
        !isGroundElementCollision(26, 8) &&
        !isAirElementCollision(26, 8) &&
        y > maxYPosition
        ) {
      x -= constants::mapSpeed;
      velocityX = 0;
    } else {
      if (velocityY < 0 && isAirElementCollision(24, 8)) {
        velocityY = 0.03;
        jumpAfterTopCollision = true;
      } else if (!jumpAfterTopCollision) {
        y -= 2;
        velocityY = 0;
        setNewRobotMoveType(RobotMoveType::run);
        maxYPosition = y - 80;
      }
    }
  } else if (y < maxYPosition) {
    velocityY += gravity;
    jumpAfterIdle = false;
  }
  if (y >= 432) {
    y = 432;
    if (robot.getPosition().y == 432) {
      setNewRobotMoveType(RobotMoveType::run);
    }
    maxYPosition = y - 80;
  }
  if (!isAirElementCollision(24, 8)) {
    jumpAfterTopCollision = false;
  }
  setNewRobotPosition(x, y);
  if (robot.moveType == RobotMoveType::jump) {
    robotAnimations.jumpAnim(robot.sprite, velocityY, maxYPosition);
  } else if (robot.moveType == RobotMoveType::fallDown) {
    robotAnimations.jumpAnim(robot.sprite, velocityY, maxYPosition + 80);
  }
}

void RobotMovementController::idle() {
  if (
      isGroundElementCollision(24, 8) ||
      isAirElementCollision(24, 8)
      ) {
    sf::Vector2<float> robotPosition = robot.getPosition();
    setNewRobotPosition(robotPosition.x - constants::mapSpeed, robotPosition.y);
    robotAnimations.idleAnim(robot.sprite);
  } else {
    setNewRobotMoveType(RobotMoveType::run);
  }
}

void RobotMovementController::setNewRobotPosition(float x, float y) {
  robot.sprite.setPosition(x, y);
}

void RobotMovementController::setNewRobotMoveType(RobotMoveType type) {
  robot.moveType = type;
}

void RobotMovementController::setReversedRobotParams() {
  if (!reversedSprite) {
    reversedSprite = true;
    setNewRobotPosition((robot.getPosition().x - 3) + robot.spriteWidth, robot.getPosition().y);
    robot.sprite.setScale(-constants::robotScale, constants::robotScale);
    setNewRobotMoveType(RobotMoveType::run);
  }
}

void RobotMovementController::setNormalRobotParams() {
  if (reversedSprite) {
    reversedSprite = false;
    setNewRobotPosition(robot.getPosition().x - robot.spriteWidth, robot.getPosition().y);
    robot.sprite.setScale(constants::robotScale, constants::robotScale);
    setNewRobotMoveType(RobotMoveType::run);
  }
}

bool RobotMovementController::isGroundElementCollision(float widthReduction, float heightReduction) {
  return robotCollisions.isCollisionWithGroundElement(widthReduction, heightReduction, reversedSprite);
}

bool RobotMovementController::isAirElementCollision(float widthReduction, float heightReduction) {
  return robotCollisions.isCollisionWithAirElement(widthReduction, heightReduction, reversedSprite);
}
