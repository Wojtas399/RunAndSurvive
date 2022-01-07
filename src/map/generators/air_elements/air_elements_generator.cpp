#include "air_elements_generator.h"

void AirElementsGenerator::loadTextures(float elementsTranslationX) {
  if (!ground1Texture.loadFromFile("assets/map/air_ground_1.png")) {
    std::cout << "Cannot load air ground 1 texture";
  }
  if (!ground2Texture.loadFromFile("assets/map/air_ground_2.png")) {
    std::cout << "Cannot load air ground 2 texture";
  }
  if (!doubleLevelTexture.loadFromFile("assets/map/air_double_level.png")) {
    std::cout << "Cannot load air double level texture";
  }
  if (!doubleLevelReversedTexture.loadFromFile("assets/map/air_double_level_reversed.png")) {
    std::cout << "Cannot load air double level reversed texture";
  }
  setSprites(elementsTranslationX);
}

void AirElementsGenerator::move() {
  for (int i = 0; i < airElements.size(); i++) {
    setNewElementPosition(i);
  }
}

void AirElementsGenerator::draw(sf::RenderWindow &window) {
  for (MapElement &element: airElements) {
    window.draw(element.sprite);
  }
}

void AirElementsGenerator::generateNewElementsConfiguration(int generatedNumber) {
  std::vector<MapElement> elementsConfiguration = airElementsConfigurator.configurations[generatedNumber];
  for (MapElement &element: elementsConfiguration) {
    airElements.push_back(element);
  }
}

void AirElementsGenerator::changeElementsTranslation(float newTranslationX) {
  setSprites(newTranslationX);
}

void AirElementsGenerator::setSprites(float elementsTranslationX) {
  ground1Spr.setTexture(ground1Texture);
  ground2Spr.setTexture(ground2Texture);
  doubleLevelSpr.setTexture(doubleLevelTexture);
  doubleLevelReversedSpr.setTexture(doubleLevelReversedTexture);
  airElementsConfigurator.set(
      ground1Spr,
      ground2Spr,
      doubleLevelSpr,
      doubleLevelReversedSpr,
      elementsTranslationX
  );
}

void AirElementsGenerator::setNewElementPosition(int index) {
  MapElement &element = airElements[index];
  sf::Vector2<float> position = element.getSpritePosition();
  if (position.x + static_cast<float>(element.width) <= 0) {
    airElements.erase(airElements.begin() + index);
  } else {
    element.sprite.setPosition(position.x - gameParams.mapSpeed, position.y);
  }
}
