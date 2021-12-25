#include "life_service.h"

void LifeService::loadTexture() {
  if (!lifeTexture.loadFromFile("assets/ui/heart.png")) {
    std::cout << "Cannot load heart texture";
  }
  loadSprites();
}

void LifeService::draw(sf::RenderWindow &window) {
  for (const sf::Sprite& spr : lifeSprites) {
    window.draw(spr);
  }
}

void LifeService::loadSprites() {
  float x = 20;
  for (int i = 0; i < lifeAmount; i++) {
    sf::Sprite spr;
    spr.setTexture(lifeTexture);
    spr.setPosition(x, 15);
    spr.setScale(0.06, 0.06);
    x += 40;
    lifeSprites.push_back(spr);
  }
}

void LifeService::subtractLife() {
  lifeAmount--;
  if (!lifeSprites.empty()) {
    lifeSprites.pop_back();
  }
}
