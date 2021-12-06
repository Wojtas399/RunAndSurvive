#ifndef R_S_ZOMBIE_H
#define R_S_ZOMBIE_H

#include <SFML/Graphics.hpp>
#include "../../constants.h"

enum ZombieType {
  man1, man2, woman
};

enum ZombieMoveType {
  zombieRun, zombieFallDown, zombieStandUp, zombieDead
};

class Zombie {
public:
  ZombieType type;
  ZombieMoveType moveType = ZombieMoveType::zombieFallDown;
  sf::Sprite sprite;
  sf::Clock clock;
  sf::Clock standUpClock;
  bool isReversed = true;
  int runTextureCounter = 0;
  int fallDownTextureCounter = 0;
  int deadTextureCounter = 0;
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

  void setNewMoveType(ZombieMoveType zombieMoveType);
};


#endif //R_S_ZOMBIE_H
