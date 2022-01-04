#ifndef R_S_GROUND_ELEMENTS_CONFIGURATOR_H
#define R_S_GROUND_ELEMENTS_CONFIGURATOR_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "../../../models/map/map_element.h"

class GroundElementsConfigurator {
public:
  std::vector<std::vector<MapElement>> configurations;

  void set(
      sf::Sprite block,
      sf::Sprite blockDouble,
      sf::Sprite blockTriple,
      sf::Sprite stairs,
      sf::Sprite wall,
      float translationX
  );
};

#endif //R_S_GROUND_ELEMENTS_CONFIGURATOR_H
