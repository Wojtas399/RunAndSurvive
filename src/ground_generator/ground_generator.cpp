#include "ground_generator.h"

void GroundGenerator::load() {
  if (!groundTexture.loadFromFile("assets/map/ground.png")) {
    std::cout << "Cannot load ground texture";
  }
  setSprites();
  airElementsGenerator.loadTexture();
  groundElementsGenerator.loadTexture();
}

void GroundGenerator::draw(sf::RenderWindow &window) {
  window.draw(groundSpr1);
  window.draw(groundSpr2);
  airElementsGenerator.draw();
  groundElementsGenerator.draw();
}

void GroundGenerator::move() {
  setNewPosition(groundSpr1);
  setNewPosition(groundSpr2);
  airElementsGenerator.move();
  groundElementsGenerator.move();
}

void GroundGenerator::setSprites() {
  groundSpr1.setTexture(groundTexture);
  groundSpr2.setTexture(groundTexture);
  groundSpr1.setPosition(0, 514);
  groundSpr2.setPosition(1408, 514);
}

void GroundGenerator::setNewPosition(sf::Sprite &sprite) {
  sf::Vector2<float> position = sprite.getPosition();
  if (position.x < -1408) {
    sprite.setPosition(static_cast<float>(1408), position.y);
  } else {
    sprite.setPosition(static_cast<float>(position.x - constants::mapSpeed), position.y);
  }
}