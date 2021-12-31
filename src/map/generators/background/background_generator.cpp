#include "background_generator.h"

void BackgroundGenerator::loadTexture() {
  if (!backgroundTexture.loadFromFile("assets/map/background.png")) {
    std::cout << "Cannot load background image texture";
  }
  setSprites();
  setInitialPosition();
}

void BackgroundGenerator::draw(sf::RenderWindow &window) {
  window.draw(backgroundSpr);
  window.draw(secondBackgroundSpr);
  window.draw(thirdBackgroundSpr);
}

void BackgroundGenerator::move() {
  setNewPosition(backgroundSpr);
  setNewPosition(secondBackgroundSpr);
  setNewPosition(thirdBackgroundSpr);
}

void BackgroundGenerator::setInitialPosition() {
  backgroundSpr.setPosition(0, 0);
  secondBackgroundSpr.setPosition(1150, 0);
  thirdBackgroundSpr.setPosition(2300, 0);
}

void BackgroundGenerator::setSprites() {
  backgroundSpr.setTexture(backgroundTexture);
  secondBackgroundSpr.setTexture(backgroundTexture);
  thirdBackgroundSpr.setTexture(backgroundTexture);
  backgroundSpr.setScale(2, 2);
  secondBackgroundSpr.setScale(2, 2);
  thirdBackgroundSpr.setScale(2, 2);
}

void BackgroundGenerator::setNewPosition(sf::Sprite &sprite) const {
  sf::Vector2<float> position = sprite.getPosition();
  if (position.x < -1152) {
    sprite.setPosition(gameParams.backgroundStartPosition, position.y);
  } else {
    sprite.setPosition(position.x - gameParams.mapSpeed, position.y);
  }
}
