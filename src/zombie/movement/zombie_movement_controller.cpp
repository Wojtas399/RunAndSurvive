#include "zombie_movement_controller.h"

void ZombieMovementController::loadAnimationsTextures() {
  animations.loadTextures();
}

void ZombieMovementController::move(std::vector<Zombie> &zombies) {
  for (int i = 0; i < zombies.size(); i++) {
    sf::Vector2<float> position = zombies[i].getPosition();
    float newXPosition = position.x + constants::zombieLeftSpeed;
    if (newXPosition < -100 || zombies[i].deadTextureCounter >= 8) {
      zombies.erase(zombies.begin() + i);
      std::cout << "Zombies on the screen: " << zombies.size() << "\n";
    } else {
      movementController(zombies[i]);
    }
  }
}

void ZombieMovementController::movementController(Zombie &zombie) {
  if (zombie.moveType != ZombieMoveType::zombieDead) {
    if (isFreeSpaceUnder(zombie)) {
      zombie.setNewMoveType(ZombieMoveType::zombieFallDown);
    } else if (zombie.velocityY > 0) {
      zombie.velocityY = 0;
      zombie.setNewMoveType(ZombieMoveType::zombieStandUp);
    } else if (zombie.fallDownTextureCounter >= 2) {
      zombie.setNewMoveType(ZombieMoveType::zombieRun);
      zombie.fallDownTextureCounter = 0;
    }
  }
  manageMovementType(zombie);
}

void ZombieMovementController::manageMovementType(Zombie &zombie) {
  switch (zombie.moveType) {
    case zombieRun:
      run(zombie);
      break;
    case zombieFallDown:
      fallDown(zombie);
      break;
    case zombieStandUp:
      standUp(zombie);
      break;
    case zombieDead:
      dead(zombie);
      break;
  }
}

void ZombieMovementController::run(Zombie &zombie) {
  if (isNormalCollision(zombie)) {
    zombie.setHorizontalOrientation(!zombie.isReversed);
  }
  sf::Vector2<float> position = zombie.getPosition();
  basicMove(zombie, position.x, position.y);
  animations.runAnim(zombie);
}

void ZombieMovementController::fallDown(Zombie &zombie) {
  sf::Vector2<float> position = zombie.getPosition();
  float y = position.y;
  zombie.velocityY += accelerationY;
  y += zombie.velocityY;
  basicMove(zombie, position.x, y);
  animations.fallAnim(zombie);
}

void ZombieMovementController::standUp(Zombie &zombie) {
  sf::Vector2<float> position = zombie.getPosition();
  zombie.setPosition(position.x - constants::mapSpeed, position.y);
  animations.standUpAnim(zombie);
}

void ZombieMovementController::dead(Zombie &zombie) {
  sf::Vector2<float> position = zombie.getPosition();
  zombie.setPosition(position.x - constants::mapSpeed, position.y);
  animations.deadAnim(zombie);
}

void ZombieMovementController::basicMove(Zombie &zombie, float x, float y) {
  zombie.setPosition(
      zombie.isReversed ? x + constants::zombieLeftSpeed : x + constants::zombieRightSpeed,
      y
  );
}

bool ZombieMovementController::isNormalCollision(Zombie &zombie) {
  return collisions.isCollisionWithGroundElement(zombie, 10, 10, 8) ||
         collisions.isCollisionWithAirElement(zombie, 10, 10, 5, 8);
}

bool ZombieMovementController::isFreeSpaceUnder(Zombie &zombie) {
  return !collisions.isCollisionWithGroundElement(zombie, 10, 10, 4) &&
         !collisions.isCollisionWithAirElement(zombie, 10, 10, 5, 4) &&
         zombie.getPosition().y < 442;
}
