#include "bullet_collisions.h"

bool BulletCollisions::isCollisionWithGroundElement(Bullet &bullet) {
  return mapElementsCollisions.isCollisionWithGroundElement(
      bullet.getBulletPosition().x,
      bullet.getBulletPosition().y,
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
      bullet.getBulletPosition().x,
      bullet.getBulletPosition().y,
      bullet.width,
      bullet.height,
      bullet.isReversed,
      6,
      6,
      0,
      0
  );
}
