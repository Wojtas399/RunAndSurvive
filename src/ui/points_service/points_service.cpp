#include "points_service.h"

void PointsService::loadTextures() {
  if (
      !number0Texture.loadFromFile("assets/ui/0.png") ||
      !number1Texture.loadFromFile("assets/ui/1.png") ||
      !number2Texture.loadFromFile("assets/ui/2.png") ||
      !number3Texture.loadFromFile("assets/ui/3.png") ||
      !number4Texture.loadFromFile("assets/ui/4.png") ||
      !number5Texture.loadFromFile("assets/ui/5.png") ||
      !number6Texture.loadFromFile("assets/ui/6.png") ||
      !number7Texture.loadFromFile("assets/ui/7.png") ||
      !number8Texture.loadFromFile("assets/ui/8.png") ||
      !number9Texture.loadFromFile("assets/ui/9.png")
      ) {
    std::cout << "Cannot load one of the point textures";
  }
  pointTextures.insert(pointTextures.end(), {
      number0Texture,
      number1Texture,
      number2Texture,
      number3Texture,
      number4Texture,
      number5Texture,
      number6Texture,
      number7Texture,
      number8Texture,
      number9Texture
  });
  loadSprites();
}

void PointsService::resetPoints() {
  points = 0;
  pointSprites.clear();
  loadSprites();
}

void PointsService::draw(sf::RenderWindow &window) {
  for (const sf::Sprite &spr: pointSprites) {
    window.draw(spr);
  }
}

void PointsService::addPointForSecond() {
  points++;
  loadSprites();
}

void PointsService::addPointsForZombie() {
  points += 3;
  loadSprites();
}

void PointsService::loadSprites() {
  std::string pointsStr = std::to_string(points);
  float x = -13;
  for (int i = 0; i < pointsStr.length(); i++) {
    int number = pointsStr[i] - '0';
    x += 30;
    if (pointsStr.length() > pointSprites.size() && i == pointsStr.length() - 1) {
      pointSprites.push_back(createPointSprite(number, x));
    } else {
      pointSprites[i] = createPointSprite(number, x);
    }
  }
}

sf::Sprite PointsService::createPointSprite(int textureCounter, float xPosition) {
  sf::Sprite spr;
  spr.setTexture(pointTextures[textureCounter]);
  spr.setPosition(xPosition, 10);
  spr.setScale(1.5, 1.5);
  return spr;
}
