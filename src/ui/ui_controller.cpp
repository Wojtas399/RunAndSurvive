#include "ui_controller.h"

void UIController::loadTextures() {
  lifeService.loadTexture();
  pointsService.loadTextures();
  zombiePointsService.loadTexture();
  buttonsService.loadTextures();
  endGameService.loadTexture();
}

int UIController::endScreenKeyController() {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    endGameService.selectButton(0);
    return -1;
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    endGameService.selectButton(1);
    return -1;
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
    return endGameService.selectedButton;
  }
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

void UIController::displayResult(sf::RenderWindow &window) {
  endGameService.draw(pointsService.pointSprites, window);
}
