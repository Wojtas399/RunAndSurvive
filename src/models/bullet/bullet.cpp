#include "bullet.h"

sf::Vector2<float> Bullet::getPosition() {
  return sprite.getPosition();
}

void Bullet::setPosition(float x, float y) {
  sprite.setPosition(x, y);
}
