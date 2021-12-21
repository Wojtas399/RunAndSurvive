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
      -1,
      8
  );
}

bool BulletCollisions::isCollisionWithZombie(Bullet &bullet, Zombie &zombie) {
  sf::Vector2<float> bulletPosition = bullet.getBulletPosition();
  sf::Vector2<float> zombiePosition = zombie.getPosition();
  float horizontalReduction = 14.0;
  float verticalReduction = 4.0;
  float bulletWidth = bullet.width - horizontalReduction;
  float bulletHeight = bullet.height - verticalReduction;
  float zombieWidth = zombie.width - horizontalReduction;
  float zombieHeight = zombie.height - verticalReduction;
  float bulletLeftBorder = bullet.isReversed ? bulletPosition.x - bulletWidth : bulletPosition.x + horizontalReduction;
  float bulletRightBorder = bullet.isReversed ? bulletPosition.x - horizontalReduction : bulletPosition.x + bulletWidth;
  float bulletBottomBorder = bulletPosition.y + bulletHeight;
  float bulletTopBorder = bulletPosition.y + verticalReduction;
  float zombieLeftBorder = zombie.isReversed ? zombiePosition.x - zombieWidth : zombiePosition.x + horizontalReduction;
  float zombieRightBorder = zombie.isReversed ? zombiePosition.x - horizontalReduction : zombiePosition.x + zombieWidth;
  float zombieBottomBorder = zombiePosition.y + zombieHeight;
  float zombieTopBorder = zombiePosition.y + verticalReduction;

  return bulletRightBorder > zombieLeftBorder &&
         bulletLeftBorder < zombieRightBorder &&
         bulletBottomBorder > zombieTopBorder &&
         bulletTopBorder < zombieBottomBorder;
}
