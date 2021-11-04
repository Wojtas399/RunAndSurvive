#ifndef R_S_GROUND_ELEMENTS_GENERATOR_H
#define R_S_GROUND_ELEMENTS_GENERATOR_H

#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>
#include <random>
#include "../../../constants.h"
#include "../../map_elements_configurators/ground_elements_configurator/ground_elements_configurator.h"

class GroundElementsGenerator {
private:
  sf::Texture simpleBlockTexture;
  sf::Texture stairsTexture;
  sf::Texture simpleWallTexture;
  sf::Sprite simpleBlockSpr;
  sf::Sprite stairsSpr;
  sf::Sprite simpleWallSpr;
  GroundElementsConfigurator groundElementsConfigurator;

  void setSprite();

  void setNewElementPosition(int index);

public:
  std::vector<MapElement> groundElements;

  void loadTexture();

  void move();

  void draw(sf::RenderWindow &window);

  void generateNewElementsConfiguration(int generatedNumber);
};

#endif //R_S_GROUND_ELEMENTS_GENERATOR_H
