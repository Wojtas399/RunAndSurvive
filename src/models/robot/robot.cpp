#include "robot.h"

sf::Vector2<float> Robot::getPosition() {
  return sprite.getPosition();
}

void Robot::setPosition(float x, float y) {
  sprite.setPosition(x, y);
}
