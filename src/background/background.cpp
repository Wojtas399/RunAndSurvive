#include "background.h"

void Background::loadTexture() {
  if (!backgroundTexture.loadFromFile("assets/map/background.png")) {
    std::cout << "Cannot load background image texture";
  }
  setSprites();
}

void Background::draw() {
  window.draw(backgroundSpr);
  window.draw(secondBackgroundSpr);
  window.draw(thirdBackgroundSpr);
}

void Background::move() {
  setNewPosition(backgroundSpr);
  setNewPosition(secondBackgroundSpr);
  setNewPosition(thirdBackgroundSpr);
}

void Background::setSprites() {
  backgroundSpr.setTexture(backgroundTexture);
  secondBackgroundSpr.setTexture(backgroundTexture);
  thirdBackgroundSpr.setTexture(backgroundTexture);
  backgroundSpr.setScale(1.7, 1.7);
  secondBackgroundSpr.setScale(1.7, 1.7);
  thirdBackgroundSpr.setScale(1.7, 1.7);
  secondBackgroundSpr.setPosition(970, 0);
  thirdBackgroundSpr.setPosition(1940, 0);
}

void Background::setNewPosition(sf::Sprite &sprite) const {
  sf::Vector2<float> position = sprite.getPosition();
  if (position.x < static_cast<float>(-windowWidth)) {
    sprite.setPosition(static_cast<float>(windowWidth), position.y);
  } else {
    sprite.setPosition(static_cast<float>(position.x - constants::mapSpeed), position.y);
  }
}
