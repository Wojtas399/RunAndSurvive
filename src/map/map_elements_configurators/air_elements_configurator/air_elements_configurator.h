#ifndef R_S_AIR_ELEMENTS_CONFIGURATIONS_H
#define R_S_AIR_ELEMENTS_CONFIGURATIONS_H

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "../../../models/map/map_element.h"
#include "../../../constants.h"

class AirElementsConfigurator {
public:
  void set(
      sf::Sprite &simpleGround,
      sf::Sprite &doubleLevel,
      sf::Sprite &doubleLevelReversed
  );

  std::vector<std::vector<MapElement>> configurations;
};

#endif //R_S_AIR_ELEMENTS_CONFIGURATIONS_H
