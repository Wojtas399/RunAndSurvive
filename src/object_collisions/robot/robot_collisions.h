#ifndef R_S_ROBOT_COLLISIONS_H
#define R_S_ROBOT_COLLISIONS_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "../../models/map/map_element.h"
#include "../../models/robot/robot.h"

class RobotCollisions {
private:
  std::vector<MapElement> &airElements;
  std::vector<MapElement> &groundElements;
  Robot &robot;

public:
  RobotCollisions(
      std::vector<MapElement> &airElements,
      std::vector<MapElement> &groundElements,
      Robot &robot
  ) : airElements(airElements), groundElements(groundElements), robot(robot) {};

  bool isCollisionWithGroundElement(float widthReduction, float heightReduction);

  bool isCollisionWithAirElement(float widthReduction, float topReduction, float bottomReduction);
};

#endif //R_S_ROBOT_COLLISIONS_H
