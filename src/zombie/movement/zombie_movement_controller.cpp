#include "zombie_movement_controller.h"

void ZombieMovementController::loadAnimationsTextures() {
  animations.loadTextures();
}

void ZombieMovementController::move(std::vector<Zombie> &zombies) {
  for (int i = 0; i < zombies.size(); i++) {
    sf::Vector2<float> position = zombies[i].getPosition();
    float newXPosition = position.x + constants::zombieLeftSpeed;
    if (newXPosition < -100) {
      zombies.erase(zombies.begin() + i);
      std::cout << "Zombies on the screen: " << zombies.size() << "\n";
    } else {
      setNewZombiePosition(zombies[i]);
    }
  }
}

void ZombieMovementController::setNewZombiePosition(Zombie &zombie) {
  float y = zombie.getPosition().y;
  bool isFallingDown = false;

  if (isFreeSpaceUnder(zombie)) {
    zombie.velocityY += accelerationY;
    y += zombie.velocityY;
    isFallingDown = true;
  } else if (isNormalCollision(zombie)) {
    zombie.setHorizontalOrientation(!zombie.isReversed);
  } else if (zombie.velocityY > 0) {
    zombie.velocityY = 0;
    isFallingDown = false;
    zombie.isAfterFallingDown = true;
  }
  if (zombie.isAfterFallingDown) {
    float x = zombie.getPosition().x;
    zombie.setPosition(x - constants::mapSpeed, y);
    animations.standUpAnim(zombie);
  } else {
    float x = zombie.getPosition().x;
    zombie.setPosition(
        zombie.isReversed ? x + constants::zombieLeftSpeed : x + constants::zombieRightSpeed,
        y
    );
    if (isFallingDown) {
      animations.fallAnim(zombie);
    } else {
      animations.runAnim(zombie);
    }
  }
}

bool ZombieMovementController::isNormalCollision(Zombie &zombie) {
  return collisions.isCollisionWithGroundElement(zombie, 10, 10, 3) ||
         collisions.isCollisionWithAirElement(zombie, 10, 10, 3, 3);
}

bool ZombieMovementController::isFreeSpaceUnder(Zombie &zombie) {
  return !collisions.isCollisionWithGroundElement(zombie, 10, 10, 1) &&
         !collisions.isCollisionWithAirElement(zombie, 10, 10, 3, 1) &&
         zombie.getPosition().y < 442;
}
