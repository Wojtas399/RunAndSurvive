#ifndef R_S_BACKGROUND_H
#define R_S_BACKGROUND_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "../../../constants.h"
#include "../../../game_params/game_params.h"

class BackgroundGenerator {
private:
  GameParams &gameParams;
  sf::Texture backgroundTexture;
  sf::Sprite backgroundSpr;
  sf::Sprite secondBackgroundSpr;
  sf::Sprite thirdBackgroundSpr;

  void setSprites();

  void setNewPosition(sf::Sprite &sprite) const;

public:
  explicit BackgroundGenerator(GameParams &gameParams) : gameParams(gameParams) {}

  void loadTexture();

  void draw(sf::RenderWindow &window);

  void move();

  void setInitialPosition();
};

#endif //R_S_BACKGROUND_H
