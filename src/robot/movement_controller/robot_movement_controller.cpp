#include "robot_movement_controller.h"

void RobotMovementController::keyController(sf::Event &event) {
  if (event.type == sf::Event::KeyPressed) {
    if (event.key.code == sf::Keyboard::Up && robot.moveType != RobotMoveType::jump) {
      if (robot.moveType == RobotMoveType::idle) {
        jumpAfterIdle = true;
      }
      robot.moveType = RobotMoveType::jump;
      velocityY = -0.08;
      accelerationY = 0.000005;
    } else if (event.key.code == sf::Keyboard::Down && robot.moveType == RobotMoveType::jump) {
      accelerationY = 0.00009;
    }
  }
}

void RobotMovementController::move() {
  switch (robot.moveType) {
    case RobotMoveType::run: {
      run();
      break;
    }
    case RobotMoveType::jump: {
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
  if (
      robotCollisions.isCollisionWithGroundElement(24, 8) ||
      robotCollisions.isCollisionWithAirElement(24, 8)
      ) {
    robot.moveType = RobotMoveType::idle;
  } else if (
      !robotCollisions.isCollisionWithGroundElement(24, 4) &&
      !robotCollisions.isCollisionWithAirElement(24, 4) &&
      robot.getPosition().y < 432
      ) {
    velocityY = 0.045;
    robot.moveType = RobotMoveType::jump;
  } else {
    robotAnimations.runAnim(robot.sprite);
  }
}

void RobotMovementController::jump() {
  float x = robot.getPosition().x;
  float y = robot.getPosition().y;
  y += velocityY;
  velocityY += accelerationY;
  bool isGroundElementCollision = robotCollisions.isCollisionWithGroundElement(24, 8);
  bool isAirElementCollision = robotCollisions.isCollisionWithAirElement(24, 8);
  bool isCollisionWithGroundElementInFront = robotCollisions.isCollisionWithGroundElement(26, 8);
  bool isCollisionWithAirElementInFront = robotCollisions.isCollisionWithAirElement(26, 8);
  if (isGroundElementCollision || isAirElementCollision) {
    if (
        jumpAfterIdle ||
        !isCollisionWithGroundElementInFront &&
        !isCollisionWithAirElementInFront
        ) {
      x -= constants::mapSpeed;
    } else {
      if (velocityY < 0 && isAirElementCollision) {
        velocityY = 0.03;
        jumpAfterTopCollision = true;
      } else if (!jumpAfterTopCollision) {
        y -= 2;
        velocityY = 0;
        robot.moveType = RobotMoveType::run;
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
      robot.moveType = RobotMoveType::run;
    }
    maxYPosition = y - 80;
  }
  if (!isAirElementCollision) {
    jumpAfterTopCollision = false;
  }
  robot.sprite.setPosition(x, y);
  robotAnimations.jumpAnim(robot.sprite, velocityY, maxYPosition);
}

void RobotMovementController::idle() {
  if (
      robotCollisions.isCollisionWithGroundElement(24, 8) ||
      robotCollisions.isCollisionWithAirElement(24, 8)
      ) {
    sf::Vector2<float> robotPosition = robot.getPosition();
    robot.sprite.setPosition(robotPosition.x - constants::mapSpeed, robotPosition.y);
    robotAnimations.idleAnim(robot.sprite);
  }
}
