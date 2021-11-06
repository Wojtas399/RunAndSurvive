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
  sf::Texture ground1Texture;
  sf::Texture ground2Texture;
  sf::Texture doubleLevelTexture;
  sf::Texture doubleLevelReversedTexture;
  sf::Sprite ground1Spr;
  sf::Sprite ground2Spr;
  sf::Sprite doubleLevelSpr;
  sf::Sprite doubleLevelReversedSpr;
  AirElementsConfigurator airElementsConfigurator;

  void setSprite();

  void setNewElementPosition(int index);

public:
  std::vector<MapElement> airElements;

  void loadTexture();

  void move();

  void draw(sf::RenderWindow &window);

  void generateNewElementsConfiguration(int generatedNumber);
};

#endif //R_S_AIR_ELEMENTS_GENERATOR_H
