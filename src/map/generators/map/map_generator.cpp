#include "map_generator.h"

void MapGenerator::load() {
  if (!groundTexture.loadFromFile("assets/map/ground.png")) {
    std::cout << "Cannot load ground texture";
  }
  setSprites();
  setGenerators();
}

void MapGenerator::setInitialParams() {
  backgroundGenerator.setInitialPosition();
  airElementsGenerator.airElements.clear();
  groundElementsGenerator.groundElements.clear();
}

void MapGenerator::draw(sf::RenderWindow &window) {
  backgroundGenerator.draw(window);
  window.draw(groundSpr1);
  window.draw(groundSpr2);
  groundElementsGenerator.draw(window);
  airElementsGenerator.draw(window);
}

void MapGenerator::move() {
  backgroundGenerator.move();
  setNewPosition(groundSpr1);
  setNewPosition(groundSpr2);
  groundElementsGenerator.move();
  airElementsGenerator.move();
  generateNewElementsConfiguration();
}

void MapGenerator::setSprites() {
  groundSpr1.setTexture(groundTexture);
  groundSpr2.setTexture(groundTexture);
  groundSpr1.setPosition(0, 614);
  groundSpr2.setPosition(1408, 614);
}

void MapGenerator::setNewPosition(sf::Sprite &sprite) const {
  sf::Vector2<float> position = sprite.getPosition();
  float x = position.x - gameParams.mapSpeed + (position.x <= -1408 ? 2 * 1408 : 0.0f);
  sprite.setPosition(x, position.y);
}

void MapGenerator::generateNewElementsConfiguration() {
  std::vector<MapElement> airElements = airElementsGenerator.airElements;
  std::vector<MapElement> groundElements = groundElementsGenerator.groundElements;
  bool isTheLastAirElementOnTheMap = isThereTheLastElementOnTheMap(airElements);
  bool isTheLastGroundElementOnTheMap = isThereTheLastElementOnTheMap(groundElements);
  if (isTheLastAirElementOnTheMap && isTheLastGroundElementOnTheMap) {
    int number = rand() % 8;
    groundElementsGenerator.generateNewElementsConfiguration(number);
    airElementsGenerator.generateNewElementsConfiguration(number);
  }
}

void MapGenerator::setGenerators() {
  backgroundGenerator.loadTexture();
  groundElementsGenerator.loadTexture();
  airElementsGenerator.loadTexture();
  int firstConfigurationNumber = rand() % 8;
  groundElementsGenerator.generateNewElementsConfiguration(firstConfigurationNumber);
  airElementsGenerator.generateNewElementsConfiguration(firstConfigurationNumber);
}

bool MapGenerator::isThereTheLastElementOnTheMap(std::vector<MapElement> elements) {
  if (!elements.empty()) {
    typedef MapElement MapElem;
    MapElem element = elements[elements.size() - 1];
    if (element.getSpritePosition().x + static_cast<float>(element.width) <= 1400) {
      return true;
    } else {
      return false;
    }
  }
  return true;
}
