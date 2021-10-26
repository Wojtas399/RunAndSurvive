#ifndef R_S_ROBOT_H
#define R_S_ROBOT_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "robot_animations/robot_animations.h"

class Robot {
private:
  sf::Sprite characterSpr;
  RobotAnimations animations;

public:
  void load();

  void draw(sf::RenderWindow &window);
};

#endif //R_S_ROBOT_H
