#include "air_elements_generator.h"

void AirElementsGenerator::loadTexture() {
  if (!simpleGroundTexture.loadFromFile("assets/map/simple_ground.png")) {
    std::cout << "Cannot load simple ground texture";
  }
  if (!doubleLevelGroundTexture.loadFromFile("assets/map/double_level_ground.png")) {
    std::cout << "Cannot load double level ground texture";
  }
  if (!doubleLevelGroundReversedTexture.loadFromFile("assets/map/double_level_ground_reversed.png")) {
    std::cout << "Cannot load double level ground reversed texture";
  }
  setSprite();
}

void AirElementsGenerator::move() {
  for (MapElement &element: airElements) {
    setNewElementPosition(element);
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

void AirElementsGenerator::setSprite() {
  simpleGroundSpr.setTexture(simpleGroundTexture);
  doubleLevelGroundSpr.setTexture(doubleLevelGroundTexture);
  doubleLevelGroundReversedSpr.setTexture(doubleLevelGroundReversedTexture);
  airElementsConfigurator.set(
      simpleGroundSpr,
      doubleLevelGroundSpr,
      doubleLevelGroundReversedSpr
  );
}

void AirElementsGenerator::setNewElementPosition(MapElement &element) {
  sf::Vector2<float> position = element.getSpritePosition();
  if (position.x + static_cast<float>(element.width) <= 0) {
    airElements.erase(airElements.begin());
  } else {
    element.sprite.setPosition(position.x - constants::mapSpeed, position.y);
  }
}
