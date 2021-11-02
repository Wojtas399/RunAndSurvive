#ifndef R_S_ROBOT_H
#define R_S_ROBOT_H

#include <SFML/Graphics.hpp>
#include "../../constants.h"

enum RobotMoveType {run, jump, idle, fallDown, slide};

class Robot {
public:
  sf::Sprite sprite;
  RobotMoveType moveType = RobotMoveType::run;
  float spriteWidth = 567 * constants::robotScale;
  float spriteHeight = 556 * constants::robotScale;

  sf::Vector2<float> getPosition();
};

#endif //R_S_ROBOT_H
