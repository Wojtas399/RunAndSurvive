#ifndef R_S_ROBOT_ANIMATIONS_H
#define R_S_ROBOT_ANIMATIONS_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "../textures/robot_textures.h"

class RobotAnimations {
private:
  RobotTextures &textures;
  sf::Clock clock;
  int runTextureCounter = 0;
  int idleTextureCounter = 0;
  int slideTextureCounter = 0;
  int shootTextureCounter = 0;
public:
  explicit RobotAnimations(RobotTextures &textures): textures(textures) {}

  void loadTextures();

  void runAnim(sf::Sprite &character, bool isFastRun);

  void jumpAnim(sf::Sprite &robotSprite, float velocityY, float maxYPosition);

  void idleAnim(sf::Sprite &robotSprite);

  void slideAnim(sf::Sprite &robotSprite);

  void shootAnim(sf::Sprite &robotSprite, bool &isShoot);

  void resetShootAnimCounter();
};

#endif //R_S_ROBOT_ANIMATIONS_H
