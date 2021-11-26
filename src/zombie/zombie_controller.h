#ifndef R_S_ZOMBIE_CONTROLLER_H
#define R_S_ZOMBIE_CONTROLLER_H


#include "textures/zombie_textures.h"
#include "../models/zombie/zombie.h"
#include "../constants.h"
#include "movement/zombie_movement_controller.h"

class ZombieController {
private:
  ZombieMovementController &movementController;
  std::vector<Zombie> zombies;
  sf::Clock clock;

  void addZombie();

  static ZombieType getZombieType(int typeIndex);

public:
  explicit ZombieController(
      ZombieMovementController &zombieMovementController
  ) : movementController(zombieMovementController) {}

  void loadTextures();

  void move();

  void draw(sf::RenderWindow &window);
};


#endif //R_S_ZOMBIE_CONTROLLER_H
