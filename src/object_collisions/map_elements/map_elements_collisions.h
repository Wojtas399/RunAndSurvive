#ifndef R_S_MAP_ELEMENTS_COLLISIONS_H
#define R_S_MAP_ELEMENTS_COLLISIONS_H

#include <vector>
#include "../../models/map/map_element.h"

class MapElementsCollisions {
private:
  std::vector<MapElement> &airElements;
  std::vector<MapElement> &groundElements;

public:
  MapElementsCollisions(
      std::vector<MapElement> &airElements,
      std::vector<MapElement> &groundElements
  ) : airElements(airElements), groundElements(groundElements) {};

  bool isCollisionWithGroundElement(
      float x,
      float y,
      float width,
      float height,
      bool isReversed,
      float leftReduction,
      float rightReduction,
      float heightReduction
  );

  bool isCollisionWithAirElement(
      float x,
      float y,
      float width,
      float height,
      bool isReversed,
      float leftReduction,
      float rightReduction,
      float topReduction,
      float bottomReduction
  );
};

#endif //R_S_MAP_ELEMENTS_COLLISIONS_H
