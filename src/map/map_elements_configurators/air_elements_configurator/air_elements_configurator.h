#ifndef R_S_AIR_ELEMENTS_CONFIGURATIONS_H
#define R_S_AIR_ELEMENTS_CONFIGURATIONS_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "../../../models/map/map_element.h"

class AirElementsConfigurator {
public:
  std::vector<std::vector<MapElement>> configurations;

  void set(
      sf::Sprite &ground1,
      sf::Sprite &ground2,
      sf::Sprite &doubleLevel,
      sf::Sprite &doubleLevelReversed,
      float translationX
  );
};

#endif //R_S_AIR_ELEMENTS_CONFIGURATIONS_H
