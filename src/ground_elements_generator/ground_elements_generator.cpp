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
  generateNewElement();
  for (sf::Sprite &element: groundElements) {
    setNewElementPosition(element);
  }
}

void GroundElementsGenerator::draw() {
  for (sf::Sprite &element: groundElements) {
    window.draw(element);
  }
}

void GroundElementsGenerator::setSprite() {
  simpleBlockSpr.setTexture(simpleBlockTexture);
  stairsSpr.setTexture(stairsTexture);
  simpleWallSpr.setTexture(simpleWallTexture);
}

void GroundElementsGenerator::generateNewElement() {
  timerEnd = std::chrono::steady_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(timerEnd - timerStart).count();
  std::vector<sf::Sprite> elements = {
      simpleBlockSpr,
      stairsSpr,
      simpleWallSpr,
  };
  float elementsYPositions[3] = {
    450,
    322,
    450,
  };
  if (duration >= 3000) {
    std::uniform_int_distribution<int> dist(0, 2);
    if (groundElements.size() <= maxElementsAmount) {
      int generatedNumber = dist(random_generator);
      sf::Sprite newElement = elements[generatedNumber];
      newElement.setPosition(1400, elementsYPositions[generatedNumber]);
      groundElements.push_back(newElement);
    }
    timerStart = std::chrono::steady_clock::now();
  }
}

void GroundElementsGenerator::setNewElementPosition(sf::Sprite &element) {
  sf::Vector2<float> position = element.getPosition();
  if (position.x <= -400) {
    groundElements.erase(groundElements.begin());
  } else {
    element.setPosition(position.x - constants::mapSpeed, position.y);
  }
}