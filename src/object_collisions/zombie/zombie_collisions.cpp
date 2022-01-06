#include "zombie_collisions.h"

bool ZombieCollisions::isCollisionWithGroundElement(float x, float y, bool isReversed) {
  return mapElementsCollisions.isCollisionWithGroundElement(
      x,
      y,
      spriteWidth,
      spriteHeight,
      isReversed,
      26,
      26,
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
      26,
      26,
      5,
      5
  );
}
