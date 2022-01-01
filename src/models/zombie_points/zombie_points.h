#ifndef R_S_ZOMBIE_POINTS_H
#define R_S_ZOMBIE_POINTS_H

#include <SFML/Graphics.hpp>

class ZombiePoints {
public:
  sf::Sprite sprite;
  int fadeAnimCounter = 0;
  sf::Clock animClock;
};


#endif //R_S_ZOMBIE_POINTS_H
