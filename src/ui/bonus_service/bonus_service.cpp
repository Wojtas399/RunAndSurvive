#include "bonus_service.h"

void BonusService::loadTexture() {
 if(!bonusTexture.loadFromFile("assets/ui/bonus.png")) {
   std::cout << "Cannot load bonus texture\n";
 }
 setSprite();
}

void BonusService::draw(sf::RenderWindow &window) {
  window.draw(bonusSprite);
}

void BonusService::setSprite() {
  bonusSprite.setTexture(bonusTexture);
  bonusSprite.setScale(0.25, 0.25);
  bonusSprite.setPosition(20, 120);
}
