#include "global_controller.h"

void GlobalController::loadTextures() {
  mapGenerator.load();
  robotController.loadTextures();
  zombieController.loadTextures();
  pointsService.loadTextures();
  lifeService.loadTexture();
  pointsService.setPointSprites();
  uiService.loadTextures();
}

void GlobalController::resetClock() {
  pointsClock.restart();
}

void GlobalController::step() {
  moveElements();
  if (gameClock.getElapsedTime().asMilliseconds() >= 30000) {
    updateGameParams();
  }
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
  uiService.draw(window);
}

void GlobalController::setInitialGameParams() {
  pointsService.resetPoints();
  lifeService.setInitialLifeAmount();
  gameParams.setInitialValues();
  mapGenerator.setInitialParams();
  robotController.setInitialPosition();
  zombieController.setInitialParams();
  gameClock.restart();
  pointsClock.restart();
}

void GlobalController::moveElements() {
  mapGenerator.move();
  robotController.move();
  zombieController.move();
  uiService.move();
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
        float zombieXCenter = zombie.isReversed ? -60 : -3;
        uiService.addZombiePoints(
            zombie.getPosition().x - gameParams.mapSpeed + zombieXCenter,
            zombie.getPosition().y
        );
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

void GlobalController::updateGameParams() {
  gameParams.mapSpeed += 0.1;
  gameParams.robotLeftVelocityX -= 0.15;
  gameParams.zombieGeneratingTime -= 50;
  gameParams.zombieDefaultLeftVelocityX -= 0.1;
  gameParams.zombieDefaultRightVelocityX -= 0.1;
  gameParams.zombieStartXPosition += 10;
  gameParams.bulletLeftVelocityX -= 0.1;
  std::cout << "CHANGED PARAMS!\n";
  gameClock.restart();
}
