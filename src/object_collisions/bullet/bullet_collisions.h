#ifndef R_S_BULLET_COLLISIONS_H
#define R_S_BULLET_COLLISIONS_H

#include "../../models/map/map_element.h"
#include "../../models/bullet/bullet.h"
#include "../map_elements/map_elements_collisions.h"
#include "../../models/zombie/zombie.h"

class BulletCollisions {
private:
  MapElementsCollisions &mapElementsCollisions;

public:
  explicit BulletCollisions(MapElementsCollisions &mapElementsCollisions)
      : mapElementsCollisions(mapElementsCollisions) {}

  bool isCollisionWithGroundElement(Bullet &bullet);

  bool isCollisionWithAirElement(Bullet &bullet);

  bool isCollisionWithZombie(Bullet &bullet, Zombie &zombie);
};

#endif //R_S_BULLET_COLLISIONS_H
