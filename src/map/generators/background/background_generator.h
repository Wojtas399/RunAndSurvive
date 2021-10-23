#ifndef R_S_BACKGROUND_H
#define R_S_BACKGROUND_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "../../../constants.h"

class BackgroundGenerator {
private:
  sf::Texture backgroundTexture;
  sf::Sprite backgroundSpr;
  sf::Sprite secondBackgroundSpr;
  sf::Sprite thirdBackgroundSpr;

  void setSprites();

  static void setNewPosition(sf::Sprite &sprite) ;

public:
  void loadTexture();

  void draw(sf::RenderWindow &window);

  void move();
};

#endif //R_S_BACKGROUND_H
