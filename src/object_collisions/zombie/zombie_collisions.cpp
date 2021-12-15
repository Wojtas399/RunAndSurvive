#include "zombie_collisions.h"

bool ZombieCollisions::isCollisionWithGroundElement(float x, float y, const Zombie& zombie) {
  return mapElementsCollisions.isCollisionWithGroundElement(
      x,
      y,
      zombie.width,
      zombie.height,
      zombie.isReversed,
      14,
      14,
      5
  );
}

bool ZombieCollisions::isCollisionWithAirElement(float x, float y, const Zombie& zombie) {
  return mapElementsCollisions.isCollisionWithAirElement(
      x,
      y,
      zombie.width,
      zombie.height,
      zombie.isReversed,
      14,
      14,
      8,
      5
  );
}
