#include "zombie_movement_controller.h"

void ZombieMovementController::loadAnimationsTextures() {
  animations.loadTextures();
}

void ZombieMovementController::move(std::vector<Zombie> &zombies) {
  for (int i = 0; i < zombies.size(); i++) {
    sf::Vector2<float> position = zombies[i].getPosition();
    float newXPosition = position.x + zombies[i].velocityX;
    if (newXPosition < -100 || zombies[i].deadTextureCounter >= 8) {
      zombies.erase(zombies.begin() + i);
    } else {
      manageMovementType(zombies[i]);
    }
  }
}

void ZombieMovementController::manageMovementType(Zombie &zombie) {
  switch (zombie.moveType) {
    case zombieWalk:
      walk(zombie);
      break;
    case zombieFallDown:
      fallDown(zombie);
      break;
    case zombieAttack:
      attack(zombie);
      break;
    case zombieIdle:
      idle(zombie);
      break;
    case zombieDead:
      dead(zombie);
      break;
  }
}

void ZombieMovementController::walk(Zombie &zombie) {
  sf::Vector2<float> position = zombie.getPosition();
  float x = position.x;
  float y = position.y;
  bool isReversed = zombie.isReversed;
  float velocityX = zombie.velocityX;
  if (isCollisionForward(x, y, velocityX, isReversed)) {
    zombie.setHorizontalOrientation(!isReversed);
  }
  if (position.y < 542 && isFreeSpaceUnder(x, y, 10, isReversed)) {
    zombie.setNewMoveType(ZombieMoveType::zombieFallDown);
  }
  position = zombie.getPosition();
  zombie.setPosition(position.x + zombie.velocityX, position.y);
  animations.walkAnim(zombie);
}

void ZombieMovementController::fallDown(Zombie &zombie) {
  sf::Vector2<float> position = zombie.getPosition();
  float y = position.y;
  float x = position.x;
  bool isReversed = zombie.isReversed;
  float velocityY = zombie.velocityY;
  float velocityX = zombie.isReversed ? zombie.velocityXLeft : zombie.velocityXRight;
  bool stopVerticalMovement = false;

  if (velocityY > 0 && !isFreeSpaceUnder(x, y, velocityY, isReversed)) {
    verticalCorrection(x, y, velocityY, isReversed);
    zombie.setNewMoveType(ZombieMoveType::zombieWalk);
    stopVerticalMovement = true;
  }
  if (isCollisionForward(x, y, velocityX, isReversed)) {
    horizontalCorrection(x, y, velocityX, isReversed);
    velocityX = -gameParams.mapSpeed;
  }

  y += velocityY;
  x += velocityX;
  zombie.velocityY = stopVerticalMovement ? 0 : velocityY + constants::zombieAccelerationY;

  if (y >= 542) {
    y = 542;
    zombie.velocityY = 0;
    zombie.setNewMoveType(ZombieMoveType::zombieWalk);
  }

  zombie.setPosition(x, y);
  animations.fallAnim(zombie);
}

void ZombieMovementController::attack(Zombie &zombie) {
  stopMove(zombie);
  animations.attackAnim(zombie);
  if (zombie.attackTextureCounter >= 6) {
    zombie.setNewMoveType(ZombieMoveType::zombieWalk);
    zombie.attackTextureCounter = 0;
  }
}

void ZombieMovementController::idle(Zombie &zombie) {
  stopMove(zombie);
  animations.idleAnim(zombie);
}

void ZombieMovementController::dead(Zombie &zombie) {
  stopMove(zombie);
  animations.deadAnim(zombie);
}

void ZombieMovementController::stopMove(Zombie &zombie) const {
  sf::Vector2<float> position = zombie.getPosition();
  zombie.setPosition(position.x - gameParams.mapSpeed, position.y);
}

bool ZombieMovementController::isCollisionForward(float x, float y, float transformationX, bool isReversed) {
  return collisions.isCollisionWithGroundElement(x + transformationX, y, isReversed) ||
         collisions.isCollisionWithAirElement(x + transformationX, y, isReversed);
}

bool ZombieMovementController::isFreeSpaceUnder(float x, float y, float transformationY, bool isReversed) {
  return !collisions.isCollisionWithGroundElement(x, y + transformationY, isReversed) &&
         !collisions.isCollisionWithAirElement(x, y + transformationY, isReversed);
}

void ZombieMovementController::verticalCorrection(float x, float y, float &transformationY, bool isReversed) {
  float helper = !isCollisionForward(x, y, isReversed ? -5 : 5, isReversed)
                 ? 0
                 : isReversed ? 5.0f : -5.0f;
  while (!isFreeSpaceUnder(x + helper, y, transformationY, isReversed)) {
    transformationY -= 0.5;
  }
}

void ZombieMovementController::horizontalCorrection(float &x, float y, float translationX, bool isReversed) {
  float counter = isReversed ? 0.5 : -0.5;
  while (isCollisionForward(x, y, translationX, isReversed)) {
    x += counter;
  }
}
