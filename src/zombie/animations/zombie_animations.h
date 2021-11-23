#ifndef R_S_ZOMBIE_ANIMATIONS_H
#define R_S_ZOMBIE_ANIMATIONS_H

#include "../textures/zombie_textures.h"
#include "../../models/zombie/zombie.h"

class ZombieAnimations {
private:
  ZombieTextures &textures;

  void setNewRunTexture(Zombie &zombie);
public:
  explicit ZombieAnimations(ZombieTextures &textures) : textures(textures) {}

  void loadTextures();

  void runAnim(Zombie &zombie);
};


#endif //R_S_ZOMBIE_ANIMATIONS_H
