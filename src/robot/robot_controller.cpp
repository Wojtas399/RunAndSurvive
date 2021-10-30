#include "robot_controller.h"

void RobotController::loadTextures() {
  animations.loadTextures();
  robot.sprite.setScale(scale, scale);
  robot.sprite.setPosition(600, 432);
}

void RobotController::move() {
  movementController.move();
}

void RobotController::draw(sf::RenderWindow &window) const {
  window.draw(robot.sprite);
}

void RobotController::eventController() {
  movementController.keyController();
}
