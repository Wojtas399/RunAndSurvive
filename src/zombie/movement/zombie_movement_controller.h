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

  void movementController(Zombie &zombie);

  void manageMovementType(Zombie &zombie);

  void basicMove(Zombie &zombie, float x, float y);

  bool isNormalCollision(Zombie &zombie);

  bool isFreeSpaceUnder(Zombie &zombie);

  void run(Zombie &zombie);

  void fallDown(Zombie &zombie);

  void standUp(Zombie &zombie);

  void attack(Zombie &zombie);

  void dead(Zombie &zombie);
public:
  ZombieMovementController(
      ZombieAnimations &zombieAnimations,
      ZombieCollisions &zombieCollisions
  ) : animations(zombieAnimations), collisions(zombieCollisions) {}

  void loadAnimationsTextures();

  void move(std::vector<Zombie> &zombies);
};


#endif //R_S_ZOMBIE_MOVEMENT_CONTROLLER_H
