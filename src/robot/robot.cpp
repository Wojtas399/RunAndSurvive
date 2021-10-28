#include "robot.h"

void Robot::load() {
  animations.loadTextures();
  robot.setScale(xScale, yScale);
  robot.setPosition(500, 432);
}

void Robot::move() {
  controller.move(jumpNumber);
}

void Robot::draw(sf::RenderWindow &window) {
  switch (moveType) {
    case enums::RobotMoveType::run: {
      animations.run(robot);
      break;
    }
    case enums::RobotMoveType::jump: {
      animations.jump(robot, jumpNumber);
      break;
    }
  }
  window.draw(robot);
}

void Robot::movementController(sf::Event &event) {
  controller.keyController(event, jumpNumber);
}
