#ifndef R_S_AIR_ELEMENTS_GENERATOR_H
#define R_S_AIR_ELEMENTS_GENERATOR_H

#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>
#include <random>
#include "../../../constants.h"
#include "../../map_elements_configurators/air_elements_configurator/air_elements_configurator.h"
#include "../../../game_params/game_params.h"

class AirElementsGenerator {
private:
  GameParams &gameParams;
  sf::Texture ground1Texture;
  sf::Texture ground2Texture;
  sf::Texture doubleLevelTexture;
  sf::Texture doubleLevelReversedTexture;
  sf::Sprite ground1Spr;
  sf::Sprite ground2Spr;
  sf::Sprite doubleLevelSpr;
  sf::Sprite doubleLevelReversedSpr;
  AirElementsConfigurator airElementsConfigurator;

  void setSprites(float elementsTranslationX);

  void setNewElementPosition(int index);

public:
  explicit AirElementsGenerator(GameParams &gameParams) : gameParams(gameParams) {}

  std::vector<MapElement> airElements;

  void loadTextures(float elementsTranslationX);

  void move();

  void draw(sf::RenderWindow &window);

  void generateNewElementsConfiguration(int generatedNumber);

  void changeElementsTranslation(float newTranslationX);
};

#endif //R_S_AIR_ELEMENTS_GENERATOR_H
