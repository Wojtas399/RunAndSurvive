#include "ui_controller.h"

void UIController::loadTextures() {
  lifeService.loadTexture();
  pointsService.loadTextures();
  zombiePointsService.loadTexture();
  buttonsService.loadTextures();
  menuService.loadTexture();
  instructionService.loadTexture();
  endGameService.loadTexture();
}

int UIController::menuScreenKeyController() {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
    menuService.moveUp();
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
    menuService.moveDown();
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
    return menuService.selectedButton;
  }
  return -1;
}

int UIController::instructionScreenKeyController() {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
    return 0;
  }
  return -1;
}

int UIController::endScreenKeyController() {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    endGameService.moveLeft();
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    endGameService.moveRight();
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
    return endGameService.selectedButton;
  }
  return -1;
}

void UIController::move() {
  lifeService.move();
  zombiePointsService.move();
}

void UIController::draw(sf::RenderWindow &window) {
  lifeService.draw(window);
  pointsService.draw(window);
  zombiePointsService.draw(window);
}

void UIController::setInitialParams() {
  lifeService.setInitialLivesAmount();
  pointsService.resetPoints();
}

void UIController::addPointForSecond() {
  pointsService.addPointForSecond();
}

void UIController::addPointsForZombie(float zombieXPosition, float zombieYPosition) {
  pointsService.addPointsForZombie();
  zombiePointsService.addZombiePoints(zombieXPosition, zombieYPosition);
}

void UIController::displayMenu(sf::RenderWindow &window) {
  menuService.draw(window);
}

void UIController::displayInstruction(sf::RenderWindow &window) {
  instructionService.draw(window);
}

void UIController::displayResult(sf::RenderWindow &window) {
  endGameService.draw(pointsService.pointSprites, window);
}
