#include "global_controller.h"

void GlobalController::robotKeyController() {
  robotController.keyController();
}

void GlobalController::endScreenKeyController() {
  int selectedButton = uiController.endScreenKeyController();
  if (selectedButton == 0) {
    startGame();
  }
}

void GlobalController::loadTextures() {
  mapGenerator.load();
  robotController.loadTextures();
  zombieController.loadTextures();
  uiController.loadTextures();
}

void GlobalController::startGame() {
  setInitialGameParams();
  gameParams.isGameStarted = true;
}

void GlobalController::step() {
  moveElements();
  if (gameClock.getElapsedTime().asMilliseconds() >= 30000) {
    updateGameParams();
  }
  if (pointsClock.getElapsedTime().asMilliseconds() >= 1000) {
    uiController.addPointForSecond();
    pointsClock.restart();
  }
}

void GlobalController::draw(sf::RenderWindow &window) {
  mapGenerator.draw(window);
  zombieController.draw(window);
  robotController.draw(window);
  uiController.draw(window);
}

void GlobalController::setInitialGameParams() {
  pointsClock.restart();
  uiController.setInitialParams();
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
  uiController.move();
  checkCollisions();
}

void GlobalController::checkCollisions() {
  std::vector<Bullet> &bullets = robotController.shootController.allBullets;
  std::vector<Zombie> &zombies = zombieController.zombies;
  for (Zombie &zombie: zombies) {
    if (
        robotZombieCollisions.isRobotCollisionWithZombie(robot, zombie) &&
        zombie.moveType != ZombieMoveType::zombieDead &&
        zombie.moveType != ZombieMoveType::zombieFallDown
        ) {
      if (
          zombie.attackBreakClock.getElapsedTime().asMilliseconds() > 1000 &&
          zombie.moveType != ZombieMoveType::zombieDead &&
          zombie.moveType != ZombieMoveType::zombieFallDown
          ) {
        zombie.setNewMoveType(ZombieMoveType::zombieAttack);
        zombie.attackBreakClock.restart();
        setZombieOrientation(zombie);
      } else if (robot.moveType == RobotMoveType::idle && zombie.moveType != ZombieMoveType::zombieAttack) {
        zombie.setNewMoveType(ZombieMoveType::zombieIdle);
      } else {
        setZombieOrientation(zombie);
      }
    } else if (zombie.moveType == ZombieMoveType::zombieIdle) {
      zombie.setNewMoveType(ZombieMoveType::zombieWalk);
    }
    for (Bullet &bullet: bullets) {
      if (
          zombie.moveType != ZombieMoveType::zombieDead &&
          !bullet.isExplosion &&
          bulletCollisions.isCollisionWithZombie(bullet, zombie)
          ) {
        zombie.setNewMoveType(ZombieMoveType::zombieDead);
        bullet.isExplosion = true;
        setBulletExplosionPosition(bullet, zombie);
        float zombieXCenter = zombie.isReversed ? -75 : 5;
        uiController.addPointsForZombie(
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
      zombiePosition.x + (zombie.isReversed ? -42.0f : 36.0f),
      zombiePosition.y
  );
}

void GlobalController::setZombieOrientation(Zombie &zombie) {
  float robotXCenter = robot.getPosition().x - (robot.isReversed ? 60.0f : 3.0f);
  float zombieXCenter = zombie.getPosition().x + (zombie.isReversed ? -75.0f : 5.0f);
  if (zombieXCenter > robotXCenter && !zombie.isReversed) {
    zombie.setHorizontalOrientation(true);
  } else if (zombieXCenter < robotXCenter && zombie.isReversed) {
    zombie.setHorizontalOrientation(false);
  }
}

void GlobalController::updateGameParams() {
  gameParams.mapSpeed += 0.1;
  gameParams.robotLeftVelocityX -= 0.15;
  gameParams.zombieGeneratingTime -= 200;
  gameParams.zombieDefaultLeftVelocityX -= 0.1;
  gameParams.zombieDefaultRightVelocityX -= 0.1;
  gameParams.zombieStartXPosition += 10;
  gameParams.bulletLeftVelocityX -= 0.1;
  std::cout << "CHANGED PARAMS!\n";
  gameClock.restart();
}

void GlobalController::displayResult(sf::RenderWindow &window) {
  uiController.displayResult(window);
}
