#include "robot_animations.h"

void RobotAnimations::loadTextures() {
  loadRunTextures();
  loadJumpTextures();
}

void RobotAnimations::run(sf::Sprite &character) {
  move(character, runTextures);
}

void RobotAnimations::jump(sf::Sprite &character, int jumpNumber) {
  character.setTexture(jumpTextures[jumpNumber]);
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

void RobotAnimations::move(sf::Sprite &character, const std::vector<sf::Texture> &textures) {
  if (clock.getElapsedTime().asSeconds() > 0.09f) {
    character.setTexture(textures[counter]);
    counter++;
    if (counter >= textures.size()) {
      counter = 0;
    }
    clock.restart();
  }
}
