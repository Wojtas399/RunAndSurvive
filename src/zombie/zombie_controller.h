#ifndef R_S_ZOMBIE_CONTROLLER_H
#define R_S_ZOMBIE_CONTROLLER_H


#include "textures/zombie_textures.h"
#include "../models/zombie/zombie.h"
#include "animations/zombie_animations.h"

class ZombieController {
private:ZombieAnimations &animations;
  std::vector<Zombie> zombies;

public:
  explicit ZombieController(
      ZombieAnimations &zombieAnimations
  ) : animations(zombieAnimations) {}

  void loadTextures();

  void move();

  void draw(sf::RenderWindow &window);

  void addZombie();
};


#endif //R_S_ZOMBIE_CONTROLLER_H
