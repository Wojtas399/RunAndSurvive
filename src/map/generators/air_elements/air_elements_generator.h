#ifndef R_S_AIR_ELEMENTS_GENERATOR_H
#define R_S_AIR_ELEMENTS_GENERATOR_H

#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>
#include <random>
#include "../../../constants.h"
#include "../../map_elements_configurators/air_elements_configurator/air_elements_configurator.h"

class AirElementsGenerator {
private:
  sf::Texture simpleGroundTexture;
  sf::Texture doubleLevelGroundTexture;
  sf::Texture doubleLevelGroundReversedTexture;
  sf::Sprite simpleGroundSpr;
  sf::Sprite doubleLevelGroundSpr;
  sf::Sprite doubleLevelGroundReversedSpr;
  AirElementsConfigurator airElementsConfigurator;

  void setSprite();

  void setNewElementPosition(MapElement &element);

public:
  std::vector<MapElement> airElements;

  void loadTexture();

  void move();

  void draw(sf::RenderWindow &window);

  void generateNewElementsConfiguration(int generatedNumber);
};

#endif //R_S_AIR_ELEMENTS_GENERATOR_H
