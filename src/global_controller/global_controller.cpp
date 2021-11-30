#include "global_controller.h"

void GlobalController::loadTextures() {
  mapGenerator.load();
  robotController.loadTextures();
  zombieController.loadTextures();
}

void GlobalController::moveElements() {
  mapGenerator.move();
  robotController.move();
  zombieController.move();
  std::vector<Bullet> &bullets = robotController.shootController.allBullets;
  std::vector<Zombie> &zombies = zombieController.zombies;
  for (auto & zombie : zombies) {
    for (int bulletIndex = 0; bulletIndex < bullets.size(); bulletIndex++) {
      if (bulletCollisions.isCollisionWithZombie(bullets[bulletIndex], zombie)) {
        zombie.setNewMoveType(ZombieMoveType::zombieDead);
        bullets.erase(bullets.begin() + bulletIndex);
      }
    }
  }
}

void GlobalController::draw(sf::RenderWindow &window) {
  mapGenerator.draw(window);
  robotController.draw(window);
  zombieController.draw(window);
}
