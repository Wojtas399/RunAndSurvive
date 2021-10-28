#include "robot_controller.h"

void RobotController::keyController(sf::Event &event, int &jumpSpriteNumber) {
  if (
      event.type == sf::Event::KeyPressed &&
      event.key.code == sf::Keyboard::Up &&
      moveType != enums::RobotMoveType::jump
      ) {
    moveType = enums::RobotMoveType::jump;
    jumpSpriteNumber = 0;
    velocityY = -0.045;
  }
}


void RobotController::move(int &jumpSpriteNumber) {
  if (moveType == enums::RobotMoveType::jump) {
    jump(jumpSpriteNumber);
  }
}

void RobotController::jump(int &jumpSpriteNumber) {
  float x = robot.getPosition().x;
  float y = robot.getPosition().y;
  y += velocityY;
  if (y < maxYPosition) {
    velocityY += gravity;
  } else if (y >= 432) {
    y = 432;
    maxYPosition = y - 120;
    if (robot.getPosition().y == 432) {
      moveType = enums::RobotMoveType::run;
    }
  }
  robot.setPosition(x, y);
  setNewJumpSpriteNumber(jumpSpriteNumber);
}

void RobotController::setNewJumpSpriteNumber(int &jumpSpriteNumber) {
  float uppermostSections[5] = {115, 110, 105, 100, 95};
  float downwardsSections[5] = {10, 20, 30, 40, 50};
  float y = robot.getPosition().y;
  if (velocityY < 0) {
    bool isSet = false;
    int i = 0;
    while (!isSet && i < 5) {
      if (y > maxYPosition + uppermostSections[i]) {
        jumpSpriteNumber = i;
        isSet = true;
      }
      i++;
    }
  } else {
    bool isSet = false;
    int i = 0;
    while (!isSet && i < 5) {
      if (y < maxYPosition + downwardsSections[i]) {
        jumpSpriteNumber = i + 5;
        isSet = true;
      }
      i++;
    }
  }
}
