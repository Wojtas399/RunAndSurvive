#include "zombie_controller.h"

void ZombieController::loadTextures() {
  animations.loadTextures();
}

void ZombieController::move() {
  for (Zombie &zombie: zombies) {
    animations.runAnim(zombie);
  }
}

void ZombieController::draw(sf::RenderWindow &window) {
  for (const Zombie &zombie: zombies) {
    window.draw(zombie.sprite);
  }
}

void ZombieController::addZombie() {
  Zombie newZombie(ZombieType::woman);
  newZombie.setScale(0.20);
  newZombie.setPosition(700, 442);
  zombies.push_back(newZombie);
}
