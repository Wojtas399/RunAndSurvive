#ifndef R_S_ROBOT_H
#define R_S_ROBOT_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "robot_animations/robot_animations.h"
#include "controller/robot_controller.h"
#include "../enums.h"

class Robot {
private:
  sf::Sprite &robot;
  enums::RobotMoveType &moveType;
  RobotAnimations &animations;
  RobotController &controller;
  float xScale = 0.16;
  float yScale = 0.16;
  int jumpNumber = 0;

public:
  Robot(
      sf::Sprite &robot,
      enums::RobotMoveType &moveType,
      RobotAnimations &animations,
      RobotController &controller
  ) : robot(robot), moveType(moveType), animations(animations), controller(controller) {}

  void load();

  void move();

  void draw(sf::RenderWindow &window);

  void movementController(sf::Event &event);
};

#endif //R_S_ROBOT_H
