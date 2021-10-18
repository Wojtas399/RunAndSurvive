#include <SFML/Graphics.hpp>
#include <iostream>

#ifndef R_S_BACKGROUND_H
#define R_S_BACKGROUND_H

class Background {
private:
  int windowWidth;
  sf::RenderWindow &window;
  sf::Texture backgroundTexture;
  sf::Sprite backgroundSpr;
  sf::Sprite secondBackgroundSpr;
  float speed = 0.025;

  void setSprites();

  void setNewBckPosition();

  void setNewSecondBckPosition();

public:
  Background(int windowWidth, sf::RenderWindow &windowRef) : window(windowRef) {
    this->windowWidth = windowWidth;
  }

  void loadTexture();

  void draw();

  void move();
};

#endif //R_S_BACKGROUND_H
