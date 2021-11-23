#ifndef R_S_ZOMBIE_H
#define R_S_ZOMBIE_H

#include <SFML/Graphics.hpp>

enum ZombieType {
  man1,
  man2,
  woman,
};

class Zombie {
public:
  ZombieType type;
  sf::Sprite sprite;
  int runTextureCounter = 0;
  sf::Clock textureClock;

  explicit Zombie(ZombieType zombieType) {
    type = zombieType;
  }

  sf::Vector2<float> getPosition();

  void setPosition(float x, float y);

  void setTexture(sf::Texture &texture);

  void setScale(float scale);
};


#endif //R_S_ZOMBIE_H
