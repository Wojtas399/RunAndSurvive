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
  bool isKeyUpPressed = false;
  bool isKeyDownPressed = false;
  bool isKeyLeftPressed = false;
  bool isKeyRightPressed = false;
  bool isSpacePressed = false;

public:
  RobotShootController &shootController;

  RobotController(
      Robot &robot,
      RobotAnimations &robotAnimations,
      RobotMovementController &robotMovementController,
      RobotShootController &robotShootController
  ) :
      robot(robot),
      animations(robotAnimations),
      movementController(robotMovementController),
      shootController(robotShootController) {}

  void loadTextures();

  void setInitialPosition();

  void move();

  void draw(sf::RenderWindow &window) const;

  void keyController();
};

#endif //R_S_ROBOT_CONTROLLER_H
