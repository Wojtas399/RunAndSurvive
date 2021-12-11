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
  for (Zombie &zombie: zombies) {
    if (
        zombie.moveType != ZombieMoveType::zombieDead &&
        zombie.attackBreakClock.getElapsedTime().asMilliseconds() > 1000 &&
        robotZombieCollisions.isRobotCollisionWithZombie(robot, zombie)
        ) {
      zombie.setNewMoveType(ZombieMoveType::zombieAttack);
    }
    for (Bullet &bullet: bullets) {
      if (
          zombie.moveType != ZombieMoveType::zombieDead &&
          bulletCollisions.isCollisionWithZombie(bullet, zombie)
          ) {
        zombie.setNewMoveType(ZombieMoveType::zombieDead);
        bullet.isExplosion = true;
        setBulletExplosionPosition(bullet, zombie);
      }
    }
  }
}

void GlobalController::draw(sf::RenderWindow &window) {
  mapGenerator.draw(window);
  zombieController.draw(window);
  robotController.draw(window);
}

void GlobalController::setBulletExplosionPosition(Bullet &bullet, Zombie &zombie) {
  sf::Vector2<float> zombiePosition = zombie.getPosition();
  bullet.setMuzzlePosition(
      zombiePosition.x + (zombie.isReversed ? -25.0f : 22.0f),
      zombiePosition.y
  );
}
