#include "bullet_collisions.h"

bool BulletCollisions::isCollisionWithGroundElement(Bullet &bullet) {
  return mapElementsCollisions.isCollisionWithGroundElement(
      bullet.getPosition().x,
      bullet.getPosition().y,
      bullet.width,
      bullet.height,
      bullet.isReversed,
      6,
      6,
      6
  );
}

bool BulletCollisions::isCollisionWithAirElement(Bullet &bullet) {
  return mapElementsCollisions.isCollisionWithAirElement(
      bullet.getPosition().x,
      bullet.getPosition().y,
      bullet.width,
      bullet.height,
      bullet.isReversed,
      6,
      6,
      6,
      6
  );
}
