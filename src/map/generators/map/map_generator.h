#ifndef R_S_GROUND_H
#define R_S_GROUND_H

#include <SFML/Graphics.hpp>
#include <utility>
#include "../air_elements/air_elements_generator.h"
#include "../ground_elements/ground_elements_generator.h"
#include "../../../models/map/map_element.h"
#include "../../../constants.h"
#include "../background/background_generator.h"

class MapGenerator {
private:
  sf::Texture groundTexture;
  sf::Sprite groundSpr1;
  sf::Sprite groundSpr2;
  GameParams &gameParams;
  BackgroundGenerator &backgroundGenerator;
  AirElementsGenerator &airElementsGenerator;
  GroundElementsGenerator &groundElementsGenerator;
  float elementsTranslationX = constants::windowWidth;

  void setSprites();

  void setElementsTranslation();

  void setNewPosition(sf::Sprite &sprite) const;

  void generateNewElementsConfiguration();

  void setGenerators();

  bool isThereTheLastElementOnTheMap(std::vector<MapElement> elements) const;

public:
  MapGenerator(
      GameParams &gameParams,
      BackgroundGenerator &backgroundGenerator,
      GroundElementsGenerator &groundElementsGenerator,
      AirElementsGenerator &airElementsGenerator
  ) : gameParams(gameParams),
      backgroundGenerator(backgroundGenerator),
      groundElementsGenerator(groundElementsGenerator),
      airElementsGenerator(airElementsGenerator) {}

  void load();

  void setInitialParams();

  void draw(sf::RenderWindow &window);

  void move();
};

#endif //R_S_GROUND_H
