#ifndef R_S_BULLET_H
#define R_S_BULLET_H

#include <SFML/Graphics.hpp>
#include "../../constants.h"

class Bullet {
public:
  sf::Sprite bulletSprite;
  sf::Sprite muzzleSprite;
  float width = 172 * constants::bulletScale;
  float height = 139 * constants::bulletScale;
  float speed = 0.06f;
  bool isReversed = false;
  int bulletCounter = 0;
  int muzzleCounter = -1;
  sf::Clock textureClock;

  sf::Vector2<float> getBulletPosition();

  sf::Vector2<float> getMuzzlePosition();

  void setBulletPosition(float x, float y);

  void setMuzzlePosition(float x, float y);
};

#endif //R_S_BULLET_H
