#ifndef R_S_ZOMBIE_COLLISIONS_H
#define R_S_ZOMBIE_COLLISIONS_H

#include <SFML/Graphics.hpp>
#include "../map_elements/map_elements_collisions.h"
#include "../../models/zombie/zombie.h"

class ZombieCollisions {
private:
  MapElementsCollisions &mapElementsCollisions;
public:
  explicit ZombieCollisions(
      MapElementsCollisions &mapElementsCollisions
  ) : mapElementsCollisions(mapElementsCollisions) {}

  bool isCollisionWithGroundElement(
      Zombie &zombie,
      float leftReduction,
      float rightReduction,
      float heightReduction
  );

  bool isCollisionWithAirElement(
      Zombie &zombie,
      float leftReduction,
      float rightReduction,
      float topReduction,
      float bottomReduction
  );
};


#endif //R_S_ZOMBIE_COLLISIONS_H
