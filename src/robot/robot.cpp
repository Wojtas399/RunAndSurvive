#include "robot.h"

void Robot::load() {
  animations.loadTextures();
  characterSpr.setScale(0.18, 0.18);
  characterSpr.setPosition(500, 421);
}

void Robot::draw(sf::RenderWindow &window) {
  animations.run(characterSpr);
  window.draw(characterSpr);
}
