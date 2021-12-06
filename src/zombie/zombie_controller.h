#ifndef R_S_ZOMBIE_CONTROLLER_H
#define R_S_ZOMBIE_CONTROLLER_H


#include "textures/zombie_textures.h"
#include "../models/zombie/zombie.h"
#include "../constants.h"
#include "movement/zombie_movement_controller.h"

class ZombieController {
private:
  ZombieMovementController &movementController;
  sf::Clock clock;

  void addZombie();

  static ZombieType getZombieType(int typeIndex);

public:
  std::vector<Zombie> zombies;

  explicit ZombieController(
      ZombieMovementController &zombieMovementController
  ) : movementController(zombieMovementController) {}

  void loadTextures();

  void move();

  void draw(sf::RenderWindow &window);
};


#endif //R_S_ZOMBIE_CONTROLLER_H
