#include "bullet.h"

sf::Vector2<float> Bullet::getBulletPosition() {
  return bulletSprite.getPosition();
}

sf::Vector2<float> Bullet::getMuzzlePosition() {
  return muzzleSprite.getPosition();
}

void Bullet::setBulletPosition(float x, float y) {
  bulletSprite.setPosition(x, y);
}

void Bullet::setMuzzlePosition(float x, float y) {
  muzzleSprite.setPosition(x, y);
}
