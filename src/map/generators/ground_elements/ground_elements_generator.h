#ifndef R_S_GROUND_ELEMENTS_GENERATOR_H
#define R_S_GROUND_ELEMENTS_GENERATOR_H

#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>
#include <random>
#include "../../../constants.h"
#include "../../map_elements_configurators/ground_elements_configurator/ground_elements_configurator.h"
#include "../../../game_params/game_params.h"

class GroundElementsGenerator {
private:
  GameParams &gameParams;
  sf::Texture blockTexture;
  sf::Texture blockDoubleTexture;
  sf::Texture blockTripleTexture;
  sf::Texture stairsTexture;
  sf::Texture wallTexture;
  sf::Sprite blockSpr;
  sf::Sprite blockDoubleSpr;
  sf::Sprite blockTripleSpr;
  sf::Sprite stairsSpr;
  sf::Sprite wallSpr;
  GroundElementsConfigurator groundElementsConfigurator;

  void setSprites(float elementsTranslationX);

  void setNewElementPosition(int index);

public:
  explicit GroundElementsGenerator(GameParams &gameParams) : gameParams(gameParams) {}

  std::vector<MapElement> groundElements;

  void loadTextures(float elementsTranslationX);

  void move();

  void draw(sf::RenderWindow &window);

  void generateNewElementsConfiguration(int generatedNumber);

  void changeElementsTranslationX(float newTranslationX);
};

#endif //R_S_GROUND_ELEMENTS_GENERATOR_H
