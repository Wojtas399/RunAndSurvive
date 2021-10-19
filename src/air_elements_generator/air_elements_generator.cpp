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
  generateNewElement();
  for (sf::Sprite &element: airElements) {
    setNewElementPosition(element);
  }
}

void AirElementsGenerator::draw() {
  for (sf::Sprite &element: airElements) {
    window.draw(element);
  }
}

void AirElementsGenerator::setSprite() {
  simpleGroundSpr.setTexture(simpleGroundTexture);
  doubleLevelGroundSpr.setTexture(doubleLevelGroundTexture);
  doubleLevelGroundReversedSpr.setTexture(doubleLevelGroundReversedTexture);
}

void AirElementsGenerator::generateNewElement() {
  timerEnd = std::chrono::steady_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(timerEnd - timerStart).count();
  std::vector<sf::Sprite> elements = {
      simpleGroundSpr,
      doubleLevelGroundSpr,
      doubleLevelGroundReversedSpr,
  };
  if (duration >= 1500) {
    std::uniform_int_distribution<int> elementDist(0, 2);
    std::uniform_real_distribution<float> verticalPositionDist(100, 250);
    sf::Sprite newElement = elements[elementDist(random_generator)];
    newElement.setPosition(1400, verticalPositionDist(random_generator));
    airElements.push_back(newElement);
    timerStart = std::chrono::steady_clock::now();
  }
}

void AirElementsGenerator::setNewElementPosition(sf::Sprite &element) {
  sf::Vector2<float> position = element.getPosition();
  if (position.x <= -400) {
    airElements.erase(airElements.begin());
    std::cout << "Deleted element\n";
  } else {
    element.setPosition(position.x - constants::mapSpeed, position.y);
  }
}