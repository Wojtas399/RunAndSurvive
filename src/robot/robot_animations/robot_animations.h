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
  std::vector<sf::Texture> runTextures;
  std::vector<sf::Texture> jumpTextures;
  sf::Clock clock;
  int counter = 0;

  void loadRunTextures();

  void loadJumpTextures();

  void move(sf::Sprite &character, const std::vector<sf::Texture> &textures);
public:
  void loadTextures();

  void run(sf::Sprite &character);

  void jump(sf::Sprite &character, int jumpNumber);
};

#endif //R_S_ROBOT_ANIMATIONS_H
