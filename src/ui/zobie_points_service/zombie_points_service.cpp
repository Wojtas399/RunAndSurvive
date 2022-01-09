#include "zombie_points_service.h"

void ZombiePointsService::loadTexture() {
  if (!zombiePointsTexture.loadFromFile("assets/ui/points/zombiePoints.png")) {
    std::cout << "Cannot load +3 texture\n";
  }
}

void ZombiePointsService::draw(sf::RenderWindow &window) {
  for (Anim &points: zombiePoints) {
    window.draw(points.sprite);
  }
}

void ZombiePointsService::move() {
  for (int i = 0; i < zombiePoints.size(); i++) {
    Anim &points = zombiePoints[i];
    if (points.animClock.getElapsedTime().asMilliseconds() > 10) {
      if (points.animCounter <= 30) {
        points.animCounter++;
        points.animClock.restart();
        basicZombiePointsMove(points);
      } else if (points.animCounter <= 90) {
        nextZombiePointsAnimStep(points);
      }
    } else if (points.animCounter > 90) {
      deleteZombiePoints(i);
    } else {
      basicZombiePointsMove(points);
    }
  }
}

void ZombiePointsService::addZombiePoints(float x, float y) {
  Anim points;
  sf::Sprite newPointsSprite;
  newPointsSprite.setTexture(zombiePointsTexture);
  newPointsSprite.setPosition(x, y);
  points.sprite = newPointsSprite;
  zombiePoints.push_back(points);
}

void ZombiePointsService::nextZombiePointsAnimStep(Anim &points) const {
  sf::Vector2<float> position = points.sprite.getPosition();
  points.sprite.setPosition(position.x - gameParams.mapSpeed, position.y - 1.5f);
  points.sprite.setColor(sf::Color(
      255,
      255,
      255,
      255 - static_cast<int>(4.25 * (points.animCounter - 30))
  ));
  points.animCounter++;
  points.animClock.restart();
}

void ZombiePointsService::deleteZombiePoints(int index) {
  zombiePoints.erase(zombiePoints.begin() + index);
}

void ZombiePointsService::basicZombiePointsMove(Anim &points) const {
  sf::Vector2<float> position = points.sprite.getPosition();
  points.sprite.setPosition(position.x - gameParams.mapSpeed, position.y - 1.5f);
}
