#ifndef R_S_ROBOT_TEXTURES_H
#define R_S_ROBOT_TEXTURES_H

#include <SFML/Graphics.hpp>
#include <iostream>

class RobotTextures {
private:
  sf::Texture run1Texture;
  sf::Texture run2Texture;
  sf::Texture run3Texture;
  sf::Texture run4Texture;
  sf::Texture run5Texture;
  sf::Texture run6Texture;
  sf::Texture run7Texture;
  sf::Texture run8Texture;
  sf::Texture jump1Texture;
  sf::Texture jump2Texture;
  sf::Texture jump3Texture;
  sf::Texture jump4Texture;
  sf::Texture jump5Texture;
  sf::Texture jump6Texture;
  sf::Texture jump7Texture;
  sf::Texture jump8Texture;
  sf::Texture jump9Texture;
  sf::Texture jump10Texture;
  sf::Texture idle1Texture;
  sf::Texture idle2Texture;
  sf::Texture idle3Texture;
  sf::Texture idle4Texture;
  sf::Texture idle5Texture;
  sf::Texture idle6Texture;
  sf::Texture idle7Texture;
  sf::Texture idle8Texture;
  sf::Texture idle9Texture;
  sf::Texture idle10Texture;
  sf::Texture slide1Texture;
  sf::Texture slide2Texture;
  sf::Texture slide3Texture;
  sf::Texture slide4Texture;
  sf::Texture slide5Texture;
  sf::Texture slide6Texture;
  sf::Texture slide7Texture;
  sf::Texture slide8Texture;
  sf::Texture slide9Texture;
  sf::Texture slide10Texture;
  sf::Texture shoot1Texture;
  sf::Texture shoot2Texture;
  sf::Texture shoot3Texture;
  sf::Texture shoot4Texture;
  sf::Texture shoot5Texture;
  sf::Texture shoot6Texture;
  sf::Texture shoot7Texture;
  sf::Texture shoot8Texture;
  sf::Texture bullet1Texture;
  sf::Texture bullet2Texture;
  sf::Texture bullet3Texture;
  sf::Texture bullet4Texture;
  sf::Texture bullet5Texture;
  sf::Texture muzzle1Texture;
  sf::Texture muzzle2Texture;
  sf::Texture muzzle3Texture;
  sf::Texture muzzle4Texture;
  sf::Texture muzzle5Texture;

  void loadRunTextures();

  void loadJumpTextures();

  void loadIdleTextures();

  void loadSlideTextures();

  void loadShootTextures();

  void loadBulletsTextures();

  void loadMuzzleTextures();

public:
  std::vector<sf::Texture> runTextures;
  std::vector<sf::Texture> jumpTextures;
  std::vector<sf::Texture> idleTextures;
  std::vector<sf::Texture> slideTextures;
  std::vector<sf::Texture> shootTextures;
  std::vector<sf::Texture> bulletsTextures;
  std::vector<sf::Texture> muzzlesTextures;

  void load();
};

#endif //R_S_ROBOT_TEXTURES_H
