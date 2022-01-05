#ifndef R_S_ZOMBIE_ANIMATIONS_H
#define R_S_ZOMBIE_ANIMATIONS_H

#include "../textures/zombie_textures.h"
#include "../../models/zombie/zombie.h"
#include "../../ui/life_service/life_service.h"


class ZombieAnimations {
private:
  ZombieTextures &textures;
  LifeService &lifeService;

  void setNewRunTexture(Zombie &zombie);

  void setNewIdleTexture(Zombie &zombie);

  void setNewFallTexture(Zombie &zombie);

  void setNewAttackTexture(Zombie &zombie);

  void fadeOutAnim(Zombie &zombie);

public:
  ZombieAnimations(ZombieTextures &textures, LifeService &lifeService) : textures(textures), lifeService(lifeService) {}

  void loadTextures();

  void runAnim(Zombie &zombie);

  void idleAnim(Zombie &zombie);

  void fallAnim(Zombie &zombie);

  void attackAnim(Zombie &zombie);

  void deadAnim(Zombie &zombie);
};


#endif //R_S_ZOMBIE_ANIMATIONS_H
