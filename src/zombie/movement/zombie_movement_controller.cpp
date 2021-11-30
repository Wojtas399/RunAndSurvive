#include "zombie_movement_controller.h"

void ZombieMovementController::loadAnimationsTextures() {
  animations.loadTextures();
}

void ZombieMovementController::move(std::vector<Zombie> &zombies) {
  for (int i = 0; i < zombies.size(); i++) {
    sf::Vector2<float> position = zombies[i].getPosition();
    float newXPosition = position.x + constants::zombieLeftSpeed;
    if (newXPosition < -100 || zombies[i].deadTextureCounter >= 18) {
      zombies.erase(zombies.begin() + i);
      std::cout << "Zombies on the screen: " << zombies.size() << "\n";
    } else {
      movementController(zombies[i]);
    }
  }
}

void ZombieMovementController::movementController(Zombie &zombie) {
  if (isFreeSpaceUnder(zombie)) {
    zombie.setNewMoveType(ZombieMoveType::zombieFallDown);
  } else if (zombie.velocityY > 0) {
    zombie.velocityY = 0;
    zombie.setNewMoveType(ZombieMoveType::zombieStandUp);
  } else if (zombie.fallDownTextureCounter >= 2) {
    zombie.setNewMoveType(ZombieMoveType::zombieRun);
    zombie.fallDownTextureCounter = 0;
  }
  manageMovementType(zombie);
}

void ZombieMovementController::manageMovementType(Zombie &zombie) {
  float y = zombie.getPosition().y;
  float x = zombie.getPosition().x;

  if (zombie.moveType == ZombieMoveType::zombieFallDown) {
    zombie.velocityY += accelerationY;
    y += zombie.velocityY;
    basicMove(zombie, x, y);
    animations.fallAnim(zombie);
  } else if (zombie.moveType == ZombieMoveType::zombieStandUp) {
    zombie.setPosition(x - constants::mapSpeed, y);
    animations.standUpAnim(zombie);
  } else if (zombie.moveType == ZombieMoveType::zombieRun) {
    if (isNormalCollision(zombie)) {
      zombie.setHorizontalOrientation(!zombie.isReversed);
    }
    x = zombie.getPosition().x;
    basicMove(zombie, x, y);
    animations.runAnim(zombie);
  } else if (zombie.moveType == ZombieMoveType::zombieDead) {
    if (zombie.deadTextureCounter == 0) {
      zombie.sprite.setTextureRect(sf::IntRect(0, 0, 500, 400));
    }
    zombie.setPosition(x - constants::mapSpeed, y);
    animations.deadAnim(zombie);
  }
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
