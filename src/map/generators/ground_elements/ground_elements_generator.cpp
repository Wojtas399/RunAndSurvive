#include "ground_elements_generator.h"

void GroundElementsGenerator::loadTexture() {
  if (!simpleBlockTexture.loadFromFile("assets/map/simple_block.png")) {
    std::cout << "Cannot load simple block texture";
  }
  if (!stairsTexture.loadFromFile("assets/map/stairs.png")) {
    std::cout << "Cannot load stairs texture";
  }
  if (!simpleWallTexture.loadFromFile("assets/map/simple_wall.png")) {
    std::cout << "Cannot load simple wall texture";
  }
  setSprite();
}

void GroundElementsGenerator::move() {
  for (MapElement &element: groundElements) {
    setNewElementPosition(element.sprite);
  }
}

void GroundElementsGenerator::draw(sf::RenderWindow &window) {
  for (MapElement &groundElement: groundElements) {
    window.draw(groundElement.sprite);
  }
}

void GroundElementsGenerator::generateNewElementsConfiguration(int generatedNumber) {
  std::vector<MapElement> elementsConfiguration = groundElementsConfigurator.configurations[generatedNumber];
  for (MapElement &element: elementsConfiguration) {
    groundElements.push_back(element);
  }
}

void GroundElementsGenerator::setSprite() {
  simpleBlockSpr.setTexture(simpleBlockTexture);
  stairsSpr.setTexture(stairsTexture);
  simpleWallSpr.setTexture(simpleWallTexture);
  groundElementsConfigurator.set(
      simpleBlockSpr,
      stairsSpr,
      simpleWallSpr
  );
}

void GroundElementsGenerator::setNewElementPosition(sf::Sprite &element) {
  sf::Vector2<float> position = element.getPosition();
  if (position.x <= -400) {
    groundElements.erase(groundElements.begin());
  } else {
    element.setPosition(position.x - constants::mapSpeed, position.y);
  }
}
