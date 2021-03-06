#include "global_controller.h"

void GlobalController::robotKeyController() {
  robotController.keyController();
}

void GlobalController::menuScreenKeyController(sf::RenderWindow &window, bool &isMenuOpen, bool &isInstructionOpen) {
  int selectedButton = uiController.menuScreenKeyController();
  if (selectedButton == 0) {
    isMenuOpen = false;
    startGame();
  } else if (selectedButton == 1) {
    isMenuOpen = false;
    isInstructionOpen = true;
  } else if (selectedButton == 2) {
    window.close();
  }
}

void GlobalController::instructionScreenKeyController(bool &isMenuOpen, bool &isInstructionOpen) {
  int selectedButton = uiController.instructionScreenKeyController();
  if (selectedButton == 0) {
    isInstructionOpen = false;
    isMenuOpen = true;
  }
}

void GlobalController::endScreenKeyController(bool &isMenuOpen) {
  int selectedButton = uiController.endScreenKeyController();
  if (selectedButton == 0) {
    isMenuOpen = false;
    startGame();
  } else if (selectedButton == 1) {
    isMenuOpen = true;
    setInitialGameParams();
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
  if (uiController.points > 10 && uiController.points % 100 < 4 && !gameParams.isBulletBonusOn) {
    gameParams.isBulletBonusOn = true;
    gameParams.bulletBonusClock.restart();
  }
  if (gameParams.isBulletBonusOn && gameParams.bulletBonusClock.getElapsedTime().asMilliseconds() >= 20000) {
    gameParams.isBulletBonusOn = false;
  }
}

void GlobalController::draw(sf::RenderWindow &window) {
  mapGenerator.draw(window);
  zombieController.draw(window);
  robotController.draw(window);
  uiController.draw(window);
  if (gameParams.isBulletBonusOn) {
    uiController.displayBonus(window);
  }
}

void GlobalController::displayMenu(sf::RenderWindow &window) {
  mapGenerator.draw(window);
  uiController.displayMenu(window);
}

void GlobalController::displayInstruction(sf::RenderWindow &window) {
  mapGenerator.draw(window);
  uiController.displayInstruction(window);
}

void GlobalController::displayResult(sf::RenderWindow &window) {
  draw(window);
  uiController.displayResult(window);
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
  robot.moveType = RobotMoveType::run;
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
    robotAndZombieCollisions(zombie);
    for (Bullet &bullet: bullets) {
      bulletAndZombieCollisions(zombie, bullet);
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

void GlobalController::robotAndZombieCollisions(Zombie &zombie) {
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
}

void GlobalController::bulletAndZombieCollisions(Zombie &zombie, Bullet &bullet) {
  if (
      zombie.moveType != ZombieMoveType::zombieDead &&
      !bullet.isExplosion &&
      bulletCollisions.isCollisionWithZombie(bullet, zombie)
      ) {
    zombie.setNewMoveType(ZombieMoveType::zombieDead);
    if (bullet.lives == 2 && gameParams.isBulletBonusOn) {
      bullet.lives--;
    } else {
      bullet.isExplosion = true;
    }
    setBulletExplosionPosition(bullet, zombie);
    float zombieXCenter = zombie.isReversed ? -75 : 5;
    uiController.addPointsForZombie(
        zombie.getPosition().x - gameParams.mapSpeed + zombieXCenter,
        zombie.getPosition().y
    );
  }
}
