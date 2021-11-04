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
  for (int i = 0; i < groundElements.size(); i++) {
    setNewElementPosition(i);
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

void GroundElementsGenerator::setNewElementPosition(int index) {
  MapElement &element = groundElements[index];
  sf::Vector2<float> position = element.getSpritePosition();
  if (position.x <= -400) {
    groundElements.erase(groundElements.begin());
  } else {
    element.sprite.setPosition(position.x - constants::mapSpeed, position.y);
  }
}
