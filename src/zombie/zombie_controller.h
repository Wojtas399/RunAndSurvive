#ifndef R_S_ZOMBIE_CONTROLLER_H
#define R_S_ZOMBIE_CONTROLLER_H


#include "textures/zombie_textures.h"
#include "../models/zombie/zombie.h"
#include "../constants.h"
#include "movement/zombie_movement_controller.h"

class ZombieController {
private:
  GameParams &gameParams;
  ZombieMovementController &movementController;
  sf::Clock clock;

  void addZombie();

  static ZombieType getZombieType(int typeIndex);

public:
  std::vector<Zombie> zombies;

  ZombieController(
      GameParams &gameParams,
      ZombieMovementController &zombieMovementController
  ) : gameParams(gameParams), movementController(zombieMovementController) {}

  void loadTextures();

  void setInitialParams();

  void move();

  void draw(sf::RenderWindow &window);
};


#endif //R_S_ZOMBIE_CONTROLLER_H
