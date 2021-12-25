#include "global_controller.h"

void GlobalController::loadTextures() {
  mapGenerator.load();
  robotController.loadTextures();
  zombieController.loadTextures();
  pointsService.loadTextures();
  lifeService.loadTexture();
  pointsService.setPointSprites();
}

void GlobalController::resetClock() {
  pointsClock.restart();
}

void GlobalController::step() {
  moveElements();
  if (pointsClock.getElapsedTime().asMilliseconds() >= 1000) {
    pointsService.addPointForSecond();
    pointsClock.restart();
  }
}

void GlobalController::draw(sf::RenderWindow &window) {
  mapGenerator.draw(window);
  zombieController.draw(window);
  robotController.draw(window);
  pointsService.draw(window);
  lifeService.draw(window);
}

void GlobalController::moveElements() {
  mapGenerator.move();
  robotController.move();
  zombieController.move();
  checkCollisions();
}

void GlobalController::checkCollisions() {
  std::vector<Bullet> &bullets = robotController.shootController.allBullets;
  std::vector<Zombie> &zombies = zombieController.zombies;
  for (Zombie &zombie: zombies) {
    if (zombie.moveType == ZombieMoveType::zombieAttack) {
      setZombieOrientation(zombie);
    }
    if (
        zombie.moveType != ZombieMoveType::zombieDead &&
        zombie.moveType != ZombieMoveType::zombieFallDown &&
        zombie.attackBreakClock.getElapsedTime().asMilliseconds() > 1000 &&
        robotZombieCollisions.isRobotCollisionWithZombie(robot, zombie)
        ) {
      setZombieOrientation(zombie);
      zombie.setNewMoveType(ZombieMoveType::zombieAttack);
      zombie.attackBreakClock.restart();
    }
    for (Bullet &bullet: bullets) {
      if (
          zombie.moveType != ZombieMoveType::zombieDead &&
          bulletCollisions.isCollisionWithZombie(bullet, zombie)
          ) {
        zombie.setNewMoveType(ZombieMoveType::zombieDead);
        bullet.isExplosion = true;
        setBulletExplosionPosition(bullet, zombie);
        pointsService.addPointsForZombie();
      }
    }
  }
}

void GlobalController::setBulletExplosionPosition(Bullet &bullet, Zombie &zombie) {
  sf::Vector2<float> zombiePosition = zombie.getPosition();
  bullet.setMuzzlePosition(
      zombiePosition.x + (zombie.isReversed ? -28.0f : 22.0f),
      zombiePosition.y
  );
}

void GlobalController::setZombieOrientation(Zombie &zombie) {
  float robotPositionX = robot.getPosition().x + (robot.isReversed ? -24.0f : 24.0f);
  float zombiePositionX = zombie.getPosition().x;
  if (zombiePositionX > robotPositionX && !zombie.isReversed) {
    zombie.setHorizontalOrientation(true);
  } else if (zombiePositionX < robotPositionX && zombie.isReversed) {
    zombie.setHorizontalOrientation(false);
  }
}
