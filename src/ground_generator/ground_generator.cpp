#include "ground_generator.h"

void GroundGenerator::load() {
  if (!groundTexture.loadFromFile("assets/map/ground.png")) {
    std::cout << "Cannot load ground texture";
  }
  setSprite();
}

void GroundGenerator::draw(sf::RenderWindow &window) {
  window.draw(groundSpr1);
  window.draw(groundSpr2);
}

void GroundGenerator::move() {
  move(groundSpr1);
  move(groundSpr2);
}

void GroundGenerator::setSprite() {
  groundSpr1.setTexture(groundTexture);
  groundSpr2.setTexture(groundTexture);
  groundSpr1.setPosition(0, 736);
  groundSpr2.setPosition(1408, 736);
}

void GroundGenerator::move(sf::Sprite &sprite) const {
  sf::Vector2<float> position = sprite.getPosition();
  if (position.x < static_cast<float>(-1408)) {
    sprite.setPosition(static_cast<float>(1408), position.y);
  } else {
    sprite.setPosition(static_cast<float>(position.x - speed), position.y);
  }
}