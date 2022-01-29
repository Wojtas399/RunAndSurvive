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
  sf::Texture startButtonTexture;
  sf::Texture startButtonClickedTexture;
  sf::Texture instructionButtonTexture;
  sf::Texture instructionButtonClickedTexture;
  sf::Texture exitButtonTexture;
  sf::Texture exitButtonClickedTexture;
  sf::Texture returnButtonTexture;
  sf::Texture returnButtonClickedTexture;

  void loadSprites();

  void loadRestartButtonsTextures();

  void loadMenuButtonsTextures();

  void loadStartButtonsTextures();

  void loadInstructionButtonsTextures();

  void loadExitButtonsTextures();

  void loadReturnButtonsTextures();

  void loadRestartButtonsSprites();

  void loadMenuButtonsSprites();

  void loadStartButtonsSprites();

  void loadInstructionButtonsSprites();

  void loadExitButtonsSprites();

  void loadReturnButtonsSprites();

public:
  sf::Sprite restartButtonSprite;
  sf::Sprite restartButtonClickedSprite;
  sf::Sprite menuButtonSprite;
  sf::Sprite menuButtonClickedSprite;
  sf::Sprite startButtonSprite;
  sf::Sprite startButtonClickedSprite;
  sf::Sprite instructionButtonSprite;
  sf::Sprite instructionButtonClickedSprite;
  sf::Sprite exitButtonSprite;
  sf::Sprite exitButtonClickedSprite;
  sf::Sprite returnButtonSprite;
  sf::Sprite returnButtonClickedSprite;

  void loadTextures();

};


#endif //R_S_BUTTONS_SERVICE_H
