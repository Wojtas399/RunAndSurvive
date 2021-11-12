#ifndef R_S_BULLET_H
#define R_S_BULLET_H

#include <SFML/Graphics.hpp>

class Bullet {
public:
  sf::Sprite sprite;
  float speed = 0.06f;
  bool isReversed = false;
  int textureCounter = 0;
  sf::Clock textureClock;

  sf::Vector2<float> getPosition();

  void setPosition(float x, float y);
};

#endif //R_S_BULLET_H
