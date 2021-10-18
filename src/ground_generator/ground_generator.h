#include <SFML/Graphics.hpp>
#include <iostream>

#ifndef R_S_GROUND_H
#define R_S_GROUND_H

class GroundGenerator {
private:
  sf::Texture groundTexture;
  sf::Sprite groundSpr1;
  sf::Sprite groundSpr2;
  float speed = 0.025;

  void setSprite();

  void move(sf::Sprite &sprite) const;

public:
  void load();

  void draw(sf::RenderWindow &window);

  void move();
};

#endif //R_S_GROUND_H
