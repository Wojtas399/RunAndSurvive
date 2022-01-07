#ifndef R_S_ZOMBIE_COLLISIONS_H
#define R_S_ZOMBIE_COLLISIONS_H

#include <SFML/Graphics.hpp>
#include "../map_elements/map_elements_collisions.h"
#include "../../models/zombie/zombie.h"

class ZombieCollisions {
private:
  MapElementsCollisions &mapElementsCollisions;
  float spriteWidth = 400 * constants::zombieScale;
  float spriteHeight = 384 * constants::zombieScale;

public:
  explicit ZombieCollisions(MapElementsCollisions &mapElementsCollisions)
      : mapElementsCollisions(mapElementsCollisions) {}

  bool isCollisionWithGroundElement(float x, float y, bool isReversed);

  bool isCollisionWithAirElement(float x, float y, bool isReversed);
};


#endif //R_S_ZOMBIE_COLLISIONS_H
