#include "zombie_collisions.h"

bool ZombieCollisions::isCollisionWithGroundElement(
    Zombie &zombie,
    float leftReduction,
    float rightReduction,
    float heightReduction
) {
  return mapElementsCollisions.isCollisionWithGroundElement(
      zombie.getPosition().x,
      zombie.getPosition().y,
      zombie.width,
      zombie.height,
      zombie.isReversed,
      leftReduction,
      rightReduction,
      heightReduction
  );
}

bool ZombieCollisions::isCollisionWithAirElement(
    Zombie &zombie,
    float leftReduction,
    float rightReduction,
    float topReduction,
    float bottomReduction
) {
  return mapElementsCollisions.isCollisionWithAirElement(
      zombie.getPosition().x,
      zombie.getPosition().y,
      zombie.width,
      zombie.height,
      zombie.isReversed,
      leftReduction,
      rightReduction,
      topReduction,
      bottomReduction
  );
}
