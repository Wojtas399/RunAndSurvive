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

void Zombie::setScale(float scaleX, float scaleY) {
  sprite.setScale(scaleX, scaleY);
}

void Zombie::setHorizontalOrientation(bool reversed) {
  isReversed = reversed;
  setScale(reversed ? -constants::zombieScale : constants::zombieScale, constants::zombieScale);
  setPosition(getPosition().x + (reversed ? width : -width), getPosition().y);
}

void Zombie::setNewMoveType(ZombieMoveType zombieMoveType) {
  moveType = zombieMoveType;
}
