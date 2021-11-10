#ifndef R_S_ROBOT_CONTROLLER_H
#define R_S_ROBOT_CONTROLLER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "animations/robot_animations.h"
#include "movement_controller/robot_movement_controller.h"
#include "../models/robot/robot.h"
#include "../constants.h"

class RobotController {
private:
  Robot &robot;
  RobotAnimations &animations;
  RobotMovementController &movementController;
  float scale = constants::robotScale;

public:
  RobotController(
      Robot &robot,
      RobotAnimations &robotAnimations,
      RobotMovementController &robotMovementController
  ) : robot(robot), animations(robotAnimations), movementController(robotMovementController) {}

  void loadTextures();

  void move();

  void draw(sf::RenderWindow &window) const;

  void eventController();
};

#endif //R_S_ROBOT_CONTROLLER_H
