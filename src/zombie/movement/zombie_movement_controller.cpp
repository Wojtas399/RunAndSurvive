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
      run(zombie);
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

void ZombieMovementController::run(Zombie &zombie) {
  sf::Vector2<float> position = zombie.getPosition();
  if (isCollisionForward(zombie, zombie.velocityX)) {
    zombie.setHorizontalOrientation(!zombie.isReversed);
  }
  if (
      position.y < 542 &&
      isFreeSpaceUnder(position.x + (zombie.isReversed ? -11.0f : 11.0f), position.y, 10, zombie)
      ) {
    zombie.setNewMoveType(ZombieMoveType::zombieFallDown);
  }
  position = zombie.getPosition();
  zombie.setPosition(position.x + zombie.velocityX, position.y);
  animations.runAnim(zombie);
}

void ZombieMovementController::fallDown(Zombie &zombie) {
  sf::Vector2<float> position = zombie.getPosition();
  float y = position.y;
  float velocityY = zombie.velocityY;
  bool stopVerticalMovement = false;

  if (
      velocityY > 0 &&
      !isFreeSpaceUnder(position.x + (zombie.isReversed ? -11.0f : 11.0f), y, zombie.velocityY, zombie)
      ) {
    verticalCorrection(position.x, y, velocityY, zombie);
    zombie.setNewMoveType(ZombieMoveType::zombieWalk);
    stopVerticalMovement = true;
  }

  y += velocityY;
  zombie.velocityY = stopVerticalMovement ? 0 : velocityY + constants::zombieAccelerationY;

  if (y >= 542) {
    y = 542;
    zombie.velocityY = 0;
    zombie.setNewMoveType(ZombieMoveType::zombieWalk);
  }

  zombie.setPosition(position.x + zombie.velocityX, y);
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

bool ZombieMovementController::isCollisionForward(Zombie &zombie, float transformationX) {
  sf::Vector2<float> position = zombie.getPosition();
  return collisions.isCollisionWithGroundElement(position.x + transformationX, position.y - 4, zombie) ||
         collisions.isCollisionWithAirElement(position.x + transformationX, position.y - 4, zombie);
}

bool ZombieMovementController::isFreeSpaceUnder(float x, float y, float transformationY, Zombie &zombie) {
  return !collisions.isCollisionWithGroundElement(x, y + transformationY, zombie) &&
         !collisions.isCollisionWithAirElement(x, y + transformationY, zombie);
}

void ZombieMovementController::verticalCorrection(float x, float y, float &transformationY, Zombie &zombie) {
  float helper = !isCollisionForward(zombie, zombie.isReversed ? -5 : 5)
                 ? 0
                 : zombie.isReversed ? 5.0f : -5.0f;
  while (!isFreeSpaceUnder(x + helper, y, transformationY, zombie)) {
    transformationY -= 0.5;
  }
}
