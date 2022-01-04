#include "ground_elements_generator.h"

void GroundElementsGenerator::loadTextures(float elementsTranslationX) {
  if (!blockTexture.loadFromFile("assets/map/ground_block.png")) {
    std::cout << "Cannot load ground block texture";
  }
  if (!blockDoubleTexture.loadFromFile("assets/map/ground_block_double.png")) {
    std::cout << "Cannot load ground block double texture";
  }
  if (!blockTripleTexture.loadFromFile("assets/map/ground_block_triple.png")) {
    std::cout << "Cannot load ground block triple texture";
  }
  if (!stairsTexture.loadFromFile("assets/map/ground_stairs.png")) {
    std::cout << "Cannot load ground stairs texture";
  }
  if (!wallTexture.loadFromFile("assets/map/ground_wall.png")) {
    std::cout << "Cannot load ground wall texture";
  }
  setSprites(elementsTranslationX);
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

void GroundElementsGenerator::changeElementsTranslationX(float newTranslationX) {
  setSprites(newTranslationX);
}

void GroundElementsGenerator::setSprites(float elementsTranslationX) {
  blockSpr.setTexture(blockTexture);
  blockDoubleSpr.setTexture(blockDoubleTexture);
  blockTripleSpr.setTexture(blockTripleTexture);
  stairsSpr.setTexture(stairsTexture);
  wallSpr.setTexture(wallTexture);
  groundElementsConfigurator.set(
      blockSpr,
      blockDoubleSpr,
      blockTripleSpr,
      stairsSpr,
      wallSpr,
      elementsTranslationX
  );
}

void GroundElementsGenerator::setNewElementPosition(int index) {
  MapElement &element = groundElements[index];
  sf::Vector2<float> position = element.getSpritePosition();
  if (position.x <= -400) {
    groundElements.erase(groundElements.begin() + index);
  } else {
    element.sprite.setPosition(position.x - gameParams.mapSpeed, position.y);
  }
}
