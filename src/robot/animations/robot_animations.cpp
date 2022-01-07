#include "robot_animations.h"

void RobotAnimations::loadTextures() {
  textures.load();
}

void RobotAnimations::runAnim(sf::Sprite &character, bool isFastRun) {
  float timeElapsed = isFastRun ? 0.065f : 0.08f;
  if (clock.getElapsedTime().asSeconds() > timeElapsed) {
    character.setTexture(textures.runTextures[runTextureCounter]);
    runTextureCounter++;
    if (runTextureCounter >= textures.runTextures.size()) {
      runTextureCounter = 0;
    }
    clock.restart();
  }
}

void RobotAnimations::jumpAnim(sf::Sprite &robotSprite, float velocityY, float maxYPosition) {
  float uppermostSections[5] = {75, 70, 65, 60, 55};
  float downwardsSections[5] = {5, 10, 15, 20, 25};
  float y = robotSprite.getPosition().y;
  if (velocityY < 0) {
    bool isSet = false;
    int i = 0;
    while (!isSet && i < 5) {
      if (y > maxYPosition + uppermostSections[i]) {
        robotSprite.setTexture(textures.jumpTextures[i]);
        isSet = true;
      }
      i++;
    }
  } else {
    bool isSet = false;
    int i = 0;
    while (!isSet && i < 5) {
      if (y < maxYPosition + downwardsSections[i]) {
        robotSprite.setTexture(textures.jumpTextures[i + 5]);
        isSet = true;
      }
      i++;
    }
  }
}

void RobotAnimations::idleAnim(sf::Sprite &robotSprite) {
  if (clock.getElapsedTime().asMilliseconds() > 65) {
    robotSprite.setTexture(textures.idleTextures[idleTextureCounter]);
    idleTextureCounter++;
    if (idleTextureCounter >= textures.idleTextures.size()) {
      idleTextureCounter = 0;
    }
    clock.restart();
  }
}

void RobotAnimations::slideAnim(sf::Sprite &robotSprite) {
  if (clock.getElapsedTime().asSeconds() > 0.09f) {
    robotSprite.setTexture(textures.slideTextures[slideTextureCounter]);
    slideTextureCounter++;
    if (slideTextureCounter >= textures.slideTextures.size()) {
      slideTextureCounter = 0;
    }
    clock.restart();
  }
}

void RobotAnimations::shootAnim(sf::Sprite &robotSprite) {
  if (clock.getElapsedTime().asSeconds() > 0.09f) {
    robotSprite.setTexture(textures.shootTextures[shootTextureCounter]);
    shootTextureCounter++;
    if (shootTextureCounter >= textures.shootTextures.size()) {
      shootTextureCounter = 0;
    }
    clock.restart();
  }
}

void RobotAnimations::runShootAnim(sf::Sprite &robotSprite, bool isFastRun) {
  float timeElapsed = isFastRun ? 0.065f : 0.08f;
  if (clock.getElapsedTime().asSeconds() > timeElapsed) {
    robotSprite.setTexture(textures.runShootTextures[runShootTextureCounter]);
    runShootTextureCounter++;
    if (runShootTextureCounter >= textures.runShootTextures.size()) {
      runShootTextureCounter = 0;
    }
    clock.restart();
  }
}
