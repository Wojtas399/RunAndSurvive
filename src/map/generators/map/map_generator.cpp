#include "map_generator.h"

void MapGenerator::load() {
  if (!groundTexture.loadFromFile("assets/map/ground.png")) {
    std::cout << "Cannot load ground texture";
  }
  setSprites();
  setGenerators();
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
  if (position.x < -1400) {
    sprite.setPosition(1408, position.y);
  } else {
    sprite.setPosition(position.x - gameParams.mapSpeed, position.y);
  }
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
    std::cout << "Ground elements amount: " << groundElementsGenerator.groundElements.size() << "\n";
    std::cout << "Air elements amount: " << airElementsGenerator.airElements.size() << "\n";
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
