#include "ui_controller.h"

void UIController::loadTextures() {
  lifeService.loadTexture();
  pointsService.loadTextures();
  zombiePointsService.loadTexture();
  endGameService.loadTexture();
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
