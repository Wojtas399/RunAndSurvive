#ifndef R_S_ZOMBIE_H
#define R_S_ZOMBIE_H

#include <SFML/Graphics.hpp>
#include "../../constants.h"

enum ZombieType {
  man1,
  man2,
  woman,
};

class Zombie {
public:
  ZombieType type;
  sf::Sprite sprite;
  sf::Clock runClock;
  sf::Clock standUpClock;
  bool isReversed = true;
  bool isAfterFallingDown = false;
  int runTextureCounter = 0;
  int descentTextureCounter = 0;
  float width = 234 * constants::zombieScale;
  float height = 384 * constants::zombieScale;
  float velocityY = 0;

  explicit Zombie(ZombieType zombieType) {
    type = zombieType;
  }

  sf::Vector2<float> getPosition();

  void setPosition(float x, float y);

  void setTexture(sf::Texture &texture);

  void setScale(float scaleX, float scaleY);

  void setHorizontalOrientation(bool reversed);
};


#endif //R_S_ZOMBIE_H
