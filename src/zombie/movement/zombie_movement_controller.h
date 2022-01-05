#ifndef R_S_ZOMBIE_MOVEMENT_CONTROLLER_H
#define R_S_ZOMBIE_MOVEMENT_CONTROLLER_H


#include "../animations/zombie_animations.h"
#include "../../object_collisions/zombie/zombie_collisions.h"
#include "../../object_collisions/robot/robot_collisions.h"
#include "../../game_params/game_params.h"

class ZombieMovementController {
private:
  GameParams &gameParams;
  ZombieAnimations &animations;
  ZombieCollisions &collisions;

  void manageMovementType(Zombie &zombie);

  void run(Zombie &zombie);

  void fallDown(Zombie &zombie);

  void attack(Zombie &zombie);

  void idle(Zombie &zombie);

  void dead(Zombie &zombie);

  void stopMove(Zombie &zombie) const;

  bool isCollisionForward(Zombie &zombie, float transformationX);

  bool isFreeSpaceUnder(float x, float y, float transformationY, Zombie& zombie);

  void verticalCorrection(float x, float y, float &transformationY, Zombie &zombie);
public:
  ZombieMovementController(
      GameParams &gameParams,
      ZombieAnimations &zombieAnimations,
      ZombieCollisions &zombieCollisions
  ) : gameParams(gameParams), animations(zombieAnimations), collisions(zombieCollisions) {}

  void loadAnimationsTextures();

  void move(std::vector<Zombie> &zombies);
};


#endif //R_S_ZOMBIE_MOVEMENT_CONTROLLER_H
