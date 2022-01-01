#include "ui_service.h"

void UIService::loadTextures() {
  if (!zombiePointsTexture.loadFromFile("assets/ui/zombiePoints.png")) {
    std::cout << "Cannot load +3 texture\n";
  }
}

void UIService::draw(sf::RenderWindow &window) {
  for (ZombiePoints &points: zombiePoints) {
    window.draw(points.sprite);
  }
}

void UIService::move() {
  for (int i = 0; i < zombiePoints.size(); i++) {
    ZombiePoints &points = zombiePoints[i];
    if (points.fadeAnimCounter <= 10 && points.animClock.getElapsedTime().asMilliseconds() > 50) {
      nextZombiePointsAnimStep(points);
    } else if (points.fadeAnimCounter > 10) {
      deleteZombiePoints(i);
    } else {
      basicZombiePointsMove(points);
    }
  }
}

void UIService::addZombiePoints(float x, float y) {
  ZombiePoints points;
  sf::Sprite newPointsSprite;
  newPointsSprite.setTexture(zombiePointsTexture);
  newPointsSprite.setPosition(x, y);
  points.sprite = newPointsSprite;
  zombiePoints.push_back(points);
}

void UIService::nextZombiePointsAnimStep(ZombiePoints &points) const {
  sf::Vector2<float> position = points.sprite.getPosition();
  points.sprite.setPosition(position.x - gameParams.mapSpeed, position.y - 12);
  points.sprite.setColor(sf::Color(255, 255, 255, 255 - static_cast<int>(25.5 * points.fadeAnimCounter)));
  points.fadeAnimCounter++;
  points.animClock.restart();
}

void UIService::deleteZombiePoints(int index) {
  zombiePoints.erase(zombiePoints.begin() + index);
}

void UIService::basicZombiePointsMove(ZombiePoints &points) const {
  sf::Vector2<float> position = points.sprite.getPosition();
  points.sprite.setPosition(position.x - gameParams.mapSpeed, position.y);
}
