#ifndef R_S_ROBOT_H
#define R_S_ROBOT_H

#include <SFML/Graphics.hpp>
#include "../../constants.h"

enum RobotMoveType {
  run, jump, idle, slide,
};

class Robot {
public:
  sf::Sprite sprite;
  RobotMoveType moveType = RobotMoveType::run;
  bool isShoot = false;
  bool isReversed = false;
  float spriteWidth = 567 * constants::robotScale;
  float spriteHeight = 556 * constants::robotScale;

  sf::Vector2<float> getPosition();

  void setPosition(float x, float y);
};

#endif //R_S_ROBOT_H
