#include "life_service.h"

void LifeService::loadTexture() {
  if (!heartTexture.loadFromFile("assets/ui/heart.png")) {
    std::cout << "Cannot load heart texture";
  }
  loadSprites();
}

void LifeService::setInitialLivesAmount() {
  livesAmount = initialLivesAmount;
  lives.clear();
  loadSprites();
}

void LifeService::move() {
  if (livesAmount < lives.size() && lives.size() > 1) {
    Anim &lastLife = lives[lives.size() - 1];
    if (lastLife.animCounter <= 60 && lastLife.animClock.getElapsedTime().asMilliseconds() > 10) {
      nextAnimStep(lastLife);
    } else if (lastLife.animCounter > 60) {
      deleteLastLifeSprite();
    }
  } else if (livesAmount == 0 && lives.size() == 1) {
    deleteLastLifeSprite();
  }
}

void LifeService::draw(sf::RenderWindow &window) {
  for (const Anim &life: lives) {
    window.draw(life.sprite);
  }
}

void LifeService::loadSprites() {
  float x = 20;
  for (int i = 0; i < livesAmount; i++) {
    Anim live;
    sf::Sprite spr;
    spr.setTexture(heartTexture);
    spr.setPosition(x, 70);
    spr.setScale(0.06, 0.06);
    live.sprite = spr;
    x += 40;
    lives.push_back(live);
  }
}

void LifeService::subtractLife() {
  livesAmount--;
}

void LifeService::nextAnimStep(Anim &life) {
  sf::Vector2<float> position = life.sprite.getPosition();
  life.sprite.setPosition(position.x, position.y + 2);
  life.sprite.setColor(sf::Color(
      255,
      255,
      255,
      255 - static_cast<int>(4.25 * life.animCounter)
  ));
  life.animCounter++;
  life.animClock.restart();
}

void LifeService::deleteLastLifeSprite() {
  lives.pop_back();
}
