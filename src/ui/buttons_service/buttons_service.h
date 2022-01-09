#ifndef R_S_BUTTONS_SERVICE_H
#define R_S_BUTTONS_SERVICE_H

#include <SFML/Graphics.hpp>
#include "iostream"

class ButtonsService {
private:
  sf::Texture restartButtonTexture;
  sf::Texture restartButtonClickedTexture;
  sf::Texture menuButtonTexture;
  sf::Texture menuButtonClickedTexture;

  void loadSprites();

public:
  sf::Sprite restartButtonSprite;
  sf::Sprite restartButtonClickedSprite;
  sf::Sprite menuButtonSprite;
  sf::Sprite menuButtonClickedSprite;

  void loadTextures();

};


#endif //R_S_BUTTONS_SERVICE_H
