#ifndef R_S_ANIM_H
#define R_S_ANIM_H

#include <SFML/Graphics.hpp>

class Anim {
public:
  sf::Sprite sprite;
  int animCounter = 0;
  sf::Clock animClock;
};


#endif //R_S_ANIM_H
