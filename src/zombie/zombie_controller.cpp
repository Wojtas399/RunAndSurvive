#include "zombie_controller.h"

void ZombieController::loadTextures() {
  movementController.loadAnimationsTextures();
}

void ZombieController::setInitialParams() {
  zombies.clear();
  clock.restart();
}

void ZombieController::move() {
  movementController.move(zombies);
  if (clock.getElapsedTime().asMilliseconds() > gameParams.zombieGeneratingTime) {
    addZombie();
    clock.restart();
  }
}

void ZombieController::draw(sf::RenderWindow &window) {
  for (const Zombie &zombie: zombies) {
    window.draw(zombie.sprite);
  }
}

void ZombieController::addZombie() {
  int index = rand() % 3;
  float speed =  static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/0.4));
  Zombie newZombie(getZombieType(index));
  newZombie.setHorizontalOrientation(true);
  newZombie.setPosition(gameParams.zombieStartXPosition, 50);
  newZombie.velocityXLeft = gameParams.zombieDefaultLeftVelocityX - speed;
  newZombie.velocityXRight = gameParams.zombieDefaultRightVelocityX + speed;
  newZombie.velocityX = newZombie.velocityXLeft;
  newZombie.setNewMoveType(ZombieMoveType::zombieFallDown);
  zombies.push_back(newZombie);
}

ZombieType ZombieController::getZombieType(int typeIndex) {
  switch (typeIndex) {
    case 0:
      return ZombieType::man1;
    case 1:
      return ZombieType::man2;
    case 2:
      return ZombieType::woman;
    default:
      return ZombieType::man1;
  }
}
