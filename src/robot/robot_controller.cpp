#include "robot_controller.h"

void RobotController::loadTextures() {
  animations.loadTextures();
  robot.sprite.setScale(scale, scale);
  robot.sprite.setPosition(600, 432);
}

void RobotController::move() {
  movementController.move(
      isKeyUpPressed,
      isKeyDownPressed,
      isKeyLeftPressed,
      isKeyRightPressed,
      isSpacePressed
  );
  shootController.move();
}

void RobotController::draw(sf::RenderWindow &window) const {
  window.draw(robot.sprite);
  shootController.draw(window);
}

void RobotController::keyController() {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
    isKeyUpPressed = true;
    isKeyDownPressed = false;
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
    isKeyDownPressed = true;
    isKeyUpPressed = false;
  } else {
    isKeyUpPressed = false;
    isKeyDownPressed = false;
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    isKeyRightPressed = true;
    isKeyLeftPressed = false;
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    isKeyLeftPressed = true;
    isKeyRightPressed = false;
  } else {
    isKeyLeftPressed = false;
    isKeyRightPressed = false;
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
    isSpacePressed = true;
  } else {
    isSpacePressed = false;
  }
}
