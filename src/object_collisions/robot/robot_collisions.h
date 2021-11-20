#ifndef R_S_ROBOT_COLLISIONS_H
#define R_S_ROBOT_COLLISIONS_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "../../models/robot/robot.h"
#include "../map_elements/map_elements_collisions.h"

class RobotCollisions {
private:
  MapElementsCollisions &mapElementsCollisions;
  Robot &robot;

public:
  RobotCollisions(
      MapElementsCollisions &mapElementsCollisions,
      Robot &robot
  ) : mapElementsCollisions(mapElementsCollisions), robot(robot) {};

  bool isCollisionWithGroundElement(float leftReduction, float rightReduction, float heightReduction);

  bool isCollisionWithAirElement(float leftReduction, float rightReduction, float topReduction, float bottomReduction);
};

#endif //R_S_ROBOT_COLLISIONS_H
