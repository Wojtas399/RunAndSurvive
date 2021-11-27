#ifndef R_S_ZOMBIE_MOVEMENT_CONTROLLER_H
#define R_S_ZOMBIE_MOVEMENT_CONTROLLER_H


#include "../animations/zombie_animations.h"
#include "../../object_collisions/zombie/zombie_collisions.h"
#include "../../object_collisions/robot/robot_collisions.h"

class ZombieMovementController {
private:
  ZombieAnimations &animations;
  ZombieCollisions &collisions;
  const float accelerationY = 0.0001;

  void setNewZombiePosition(Zombie &zombie);

  bool isNormalCollision(Zombie &zombie);

  bool isFreeSpaceUnder(Zombie &zombie);
public:
  ZombieMovementController(
      ZombieAnimations &zombieAnimations,
      ZombieCollisions &zombieCollisions
  ) : animations(zombieAnimations), collisions(zombieCollisions) {}

  void loadAnimationsTextures();

  void move(std::vector<Zombie> &zombies);
};


#endif //R_S_ZOMBIE_MOVEMENT_CONTROLLER_H
