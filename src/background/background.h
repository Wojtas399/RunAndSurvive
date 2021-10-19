#include <SFML/Graphics.hpp>
#include <iostream>
#include "../constants.h"

#ifndef R_S_BACKGROUND_H
#define R_S_BACKGROUND_H

class Background {
private:
  int windowWidth;
  sf::RenderWindow &window;
  sf::Texture backgroundTexture;
  sf::Sprite backgroundSpr;
  sf::Sprite secondBackgroundSpr;
  sf::Sprite thirdBackgroundSpr;

  void setSprites();

  void setNewPosition(sf::Sprite &sprite) const;

public:
  Background(int windowWidth, sf::RenderWindow &windowRef) : window(windowRef) {
    this->windowWidth = windowWidth;
  }

  void loadTexture();

  void draw();

  void move();
};

#endif //R_S_BACKGROUND_H
