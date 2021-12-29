#include "background_generator.h"

void BackgroundGenerator::loadTexture() {
  if (!backgroundTexture.loadFromFile("assets/map/background.png")) {
    std::cout << "Cannot load background image texture";
  }
  setSprites();
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

void BackgroundGenerator::setSprites() {
  backgroundSpr.setTexture(backgroundTexture);
  secondBackgroundSpr.setTexture(backgroundTexture);
  thirdBackgroundSpr.setTexture(backgroundTexture);
  backgroundSpr.setScale(2, 2);
  secondBackgroundSpr.setScale(2, 2);
  thirdBackgroundSpr.setScale(2, 2);
  secondBackgroundSpr.setPosition(1149, 0);
  thirdBackgroundSpr.setPosition(2299, 0);
}

void BackgroundGenerator::setNewPosition(sf::Sprite &sprite) const {
  sf::Vector2<float> position = sprite.getPosition();
  if (position.x < -constants::windowWidth) {
    sprite.setPosition(constants::windowWidth, position.y);
  } else {
    sprite.setPosition(position.x - gameParams.mapSpeed, position.y);
  }
}
