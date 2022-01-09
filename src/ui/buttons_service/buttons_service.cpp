#include "buttons_service.h"

void ButtonsService::loadTextures() {
  if (
      !restartButtonTexture.loadFromFile("assets/ui/buttons/restart.png") ||
      !restartButtonClickedTexture.loadFromFile("assets/ui/buttons/restart_clicked.png")
      ) {
    std::cout << "Cannot load one of the restart buttons texture\n";
  }
  if (
      !menuButtonTexture.loadFromFile("assets/ui/buttons/menu.png") ||
      !menuButtonClickedTexture.loadFromFile("assets/ui/buttons/menu_clicked.png")
      ) {
    std::cout << "Cannot load one of the menu buttons texture\n";
  }
  loadSprites();
}

void ButtonsService::loadSprites() {
  restartButtonSprite.setTexture(restartButtonTexture);
  restartButtonClickedSprite.setTexture(restartButtonClickedTexture);
  menuButtonSprite.setTexture(menuButtonTexture);
  menuButtonClickedSprite.setTexture(menuButtonClickedTexture);
}
