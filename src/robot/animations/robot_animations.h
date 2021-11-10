#ifndef R_S_ROBOT_ANIMATIONS_H
#define R_S_ROBOT_ANIMATIONS_H

#include <SFML/Graphics.hpp>
#include <iostream>

class RobotAnimations {
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
  sf::Texture runShoot1Texture;
  sf::Texture runShoot2Texture;
  sf::Texture runShoot3Texture;
  sf::Texture runShoot4Texture;
  sf::Texture runShoot5Texture;
  sf::Texture runShoot6Texture;
  sf::Texture runShoot7Texture;
  sf::Texture runShoot8Texture;
  sf::Texture runShoot9Texture;
  std::vector<sf::Texture> runTextures;
  std::vector<sf::Texture> jumpTextures;
  std::vector<sf::Texture> idleTextures;
  std::vector<sf::Texture> slideTextures;
  std::vector<sf::Texture> shootTextures;
  std::vector<sf::Texture> runShootTextures;
  sf::Clock clock;
  int runTextureCounter = 0;
  int idleTextureCounter = 0;
  int slideTextureCounter = 0;

  void loadRunTextures();

  void loadJumpTextures();

  void loadIdleTextures();

  void loadSlideTextures();

  void loadShootTextures();

  void loadRunShootTextures();

public:
  void loadTextures();

  void runAnim(sf::Sprite &character, bool isFastRun);

  void jumpAnim(sf::Sprite &robotSprite, float velocityY, float maxYPosition);

  void idleAnim(sf::Sprite &robotSprite);

  void slideAnim(sf::Sprite &robotSprite);
};

#endif //R_S_ROBOT_ANIMATIONS_H
