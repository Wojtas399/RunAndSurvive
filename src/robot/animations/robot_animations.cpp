#include "robot_animations.h"

void RobotAnimations::loadTextures() {
  loadRunTextures();
  loadJumpTextures();
  loadIdleTextures();
}

void RobotAnimations::runAnim(sf::Sprite &character) {
  if (clock.getElapsedTime().asSeconds() > 0.09f) {
    character.setTexture(runTextures[counter]);
    counter++;
    if (counter >= runTextures.size()) {
      counter = 0;
    }
    clock.restart();
  }
}

void RobotAnimations::jumpAnim(sf::Sprite &robotSprite, float velocityY, float maxYPosition) {
  float uppermostSections[5] = {75, 70, 65, 60, 55};
  float downwardsSections[5] = {10, 20, 30, 40, 50};
  float y = robotSprite.getPosition().y;
  if (velocityY < 0) {
    bool isSet = false;
    int i = 0;
    while (!isSet && i < 5) {
      if (y > maxYPosition + uppermostSections[i]) {
        robotSprite.setTexture(jumpTextures[i]);
        isSet = true;
      }
      i++;
    }
  } else {
    bool isSet = false;
    int i = 0;
    while (!isSet && i < 5) {
      if (y < maxYPosition + downwardsSections[i]) {
        robotSprite.setTexture(jumpTextures[i + 5]);
        isSet = true;
      }
      i++;
    }
  }
}

void RobotAnimations::idleAnim(sf::Sprite &robotSprite) {
  if (clock.getElapsedTime().asSeconds() > 0.09f) {
    robotSprite.setTexture(idleTextures[counter]);
    counter++;
    if (counter >= idleTextures.size()) {
      counter = 0;
    }
    clock.restart();
  }
}

void RobotAnimations::loadRunTextures() {
  if (
      !run1Texture.loadFromFile("assets/robot/run_1.png") ||
      !run2Texture.loadFromFile("assets/robot/run_2.png") ||
      !run3Texture.loadFromFile("assets/robot/run_3.png") ||
      !run4Texture.loadFromFile("assets/robot/run_4.png") ||
      !run5Texture.loadFromFile("assets/robot/run_5.png") ||
      !run6Texture.loadFromFile("assets/robot/run_6.png") ||
      !run7Texture.loadFromFile("assets/robot/run_7.png") ||
      !run8Texture.loadFromFile("assets/robot/run_8.png")
      ) {
    std::cout << "Cannot load one of the run textures";
  }
  runTextures.insert(runTextures.end(), {
      run1Texture,
      run2Texture,
      run3Texture,
      run4Texture,
      run5Texture,
      run6Texture,
      run7Texture,
      run8Texture,
  });
}

void RobotAnimations::loadJumpTextures() {
  if (
      !jump1Texture.loadFromFile("assets/robot/jump_1.png") ||
      !jump2Texture.loadFromFile("assets/robot/jump_2.png") ||
      !jump3Texture.loadFromFile("assets/robot/jump_3.png") ||
      !jump4Texture.loadFromFile("assets/robot/jump_4.png") ||
      !jump5Texture.loadFromFile("assets/robot/jump_5.png") ||
      !jump6Texture.loadFromFile("assets/robot/jump_6.png") ||
      !jump7Texture.loadFromFile("assets/robot/jump_7.png") ||
      !jump8Texture.loadFromFile("assets/robot/jump_8.png") ||
      !jump9Texture.loadFromFile("assets/robot/jump_9.png") ||
      !jump10Texture.loadFromFile("assets/robot/jump_10.png")
      ) {
    std::cout << "Cannot load one of the jump textures";
  }
  jumpTextures.insert(jumpTextures.end(), {
      jump1Texture,
      jump2Texture,
      jump3Texture,
      jump4Texture,
      jump5Texture,
      jump6Texture,
      jump7Texture,
      jump8Texture,
      jump9Texture,
      jump10Texture
  });
}

void RobotAnimations::loadIdleTextures() {
  if (
      !idle1Texture.loadFromFile("assets/robot/idle_1.png") ||
      !idle2Texture.loadFromFile("assets/robot/idle_2.png") ||
      !idle3Texture.loadFromFile("assets/robot/idle_3.png") ||
      !idle4Texture.loadFromFile("assets/robot/idle_4.png") ||
      !idle5Texture.loadFromFile("assets/robot/idle_5.png") ||
      !idle6Texture.loadFromFile("assets/robot/idle_6.png") ||
      !idle7Texture.loadFromFile("assets/robot/idle_7.png") ||
      !idle8Texture.loadFromFile("assets/robot/idle_8.png") ||
      !idle9Texture.loadFromFile("assets/robot/idle_9.png") ||
      !idle10Texture.loadFromFile("assets/robot/idle_10.png")
      ) {
    std::cout << "Cannot load one of the idle textures";
  }
  idleTextures.insert(idleTextures.end(), {
      idle1Texture,
      idle2Texture,
      idle3Texture,
      idle4Texture,
      idle5Texture,
      idle6Texture,
      idle7Texture,
      idle8Texture,
      idle9Texture,
      idle10Texture
  });
}
