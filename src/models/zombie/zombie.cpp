#include "zombie.h"

sf::Vector2<float> Zombie::getPosition() {
  return sprite.getPosition();
}

void Zombie::setPosition(float x, float y) {
  sprite.setPosition(x, y);
}

void Zombie::setTexture(sf::Texture &texture) {
  sprite.setTexture(texture);
}

void Zombie::setScale(float scale) {
  sprite.setScale(scale, scale);
}
