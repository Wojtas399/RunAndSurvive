#include "robot_controller.h"

void RobotController::loadTextures() {
  animations.loadTextures();
  robot.sprite.setScale(scale, scale);
  robot.sprite.setPosition(600, 432);
}

void RobotController::move() {
  movementController.move();
  shootController.move();
}

void RobotController::draw(sf::RenderWindow &window) const {
  window.draw(robot.sprite);
  shootController.draw(window);
}

void RobotController::eventController() {
  movementController.keyController();
}
