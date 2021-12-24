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
}

void PointsService::draw(sf::RenderWindow &window) {
  for (const sf::Sprite &spr: pointSprites) {
    window.draw(spr);
  }
}

void PointsService::setPointSprites() {
  std::string pointsStr = std::to_string(points);
  float x = 0;
  for (int i = 0; i < pointsStr.length(); i++) {
    int number = pointsStr[i] - '0';
    x += 30;
    sf::Sprite spr;
    spr.setTexture(pointTextures[number]);
    spr.setPosition(x, 530);
    spr.setScale(1.5, 1.5);
    if (pointsStr.length() > pointSprites.size() && i == pointsStr.length() - 1) {
      pointSprites.push_back(spr);
    } else {
      pointSprites[i] = spr;
    }
  }
}

void PointsService::addPointForSecond() {
  points++;
  setPointSprites();
}

void PointsService::addPointsForZombie() {
  points += 3;
  setPointSprites();
}
