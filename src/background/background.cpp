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
}

void Background::move() {
  setNewBckPosition();
  setNewSecondBckPosition();
}

void Background::setSprites() {
  backgroundSpr.setTexture(backgroundTexture);
  secondBackgroundSpr.setTexture(backgroundTexture);
  backgroundSpr.setScale(2.48, 2.48);
  secondBackgroundSpr.setScale(2.48, 2.48);
  secondBackgroundSpr.setPosition(1400, 0);
}

void Background::setNewBckPosition() {
  sf::Vector2<float> bckPosition = backgroundSpr.getPosition();
  if (bckPosition.x < static_cast<float>(-windowWidth)) {
    backgroundSpr.setPosition(static_cast<float>(windowWidth), bckPosition.y);
  } else {
    backgroundSpr.setPosition(static_cast<float>(bckPosition.x - speed), bckPosition.y);
  }
}

void Background::setNewSecondBckPosition() {
  sf::Vector2<float> secondBckPosition = secondBackgroundSpr.getPosition();
  if (secondBckPosition.x < static_cast<float>(-windowWidth)) {
    secondBackgroundSpr.setPosition(static_cast<float>(windowWidth), secondBckPosition.y);
  } else {
    secondBackgroundSpr.setPosition(static_cast<float>(secondBckPosition.x - speed), secondBckPosition.y);
  }
}
