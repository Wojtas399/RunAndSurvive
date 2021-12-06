#include "zombie_controller.h"

void ZombieController::loadTextures() {
  movementController.loadAnimationsTextures();
}

void ZombieController::move() {
  movementController.move(zombies);
  if (clock.getElapsedTime().asMilliseconds() > 2000) {
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
  Zombie newZombie(getZombieType(index));
  newZombie.setHorizontalOrientation(true);
  newZombie.setPosition(1600, 50);
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
