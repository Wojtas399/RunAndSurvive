#include "zombie_collisions.h"

bool ZombieCollisions::isCollisionWithGroundElement(float x, float y, bool isReversed) {
  return mapElementsCollisions.isCollisionWithGroundElement(
      x,
      y,
      spriteWidth,
      spriteHeight,
      isReversed,
      30,
      30,
      5
  );
}

bool ZombieCollisions::isCollisionWithAirElement(float x, float y, bool isReversed) {
  return mapElementsCollisions.isCollisionWithAirElement(
      x,
      y,
      spriteWidth,
      spriteHeight,
      isReversed,
      30,
      30,
      5,
      5
  );
}
