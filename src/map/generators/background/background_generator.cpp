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
  backgroundSpr.setScale(1.7, 1.7);
  secondBackgroundSpr.setScale(1.7, 1.7);
  thirdBackgroundSpr.setScale(1.7, 1.7);
  secondBackgroundSpr.setPosition(970, 0);
  thirdBackgroundSpr.setPosition(1940, 0);
}

void BackgroundGenerator::setNewPosition(sf::Sprite &sprite) {
  sf::Vector2<float> position = sprite.getPosition();
  if (position.x < static_cast<float>(-constants::windowWidth)) {
    sprite.setPosition(static_cast<float>(constants::windowWidth), position.y);
  } else {
    sprite.setPosition(static_cast<float>(position.x - constants::mapSpeed), position.y);
  }
}
