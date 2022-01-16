#include "buttons_service.h"

void ButtonsService::loadTextures() {
  loadRestartButtonsTextures();
  loadMenuButtonsTextures();
  loadStartButtonsTextures();
  loadInstructionButtonsTextures();
  loadExitButtonsTextures();
  loadReturnButtonsTextures();
  loadSprites();
}

void ButtonsService::loadSprites() {
  loadRestartButtonsSprites();
  loadMenuButtonsSprites();
  loadStartButtonsSprites();
  loadInstructionButtonsSprites();
  loadExitButtonsSprites();
  loadReturnButtonsSprites();
}

void ButtonsService::loadRestartButtonsTextures() {
  if (
      !restartButtonTexture.loadFromFile("assets/ui/buttons/restart.png") ||
      !restartButtonClickedTexture.loadFromFile("assets/ui/buttons/restart_clicked.png")
      ) {
    std::cout << "Cannot load one of the restart buttons texture\n";
  }
}

void ButtonsService::loadMenuButtonsTextures() {
  if (
      !menuButtonTexture.loadFromFile("assets/ui/buttons/menu.png") ||
      !menuButtonClickedTexture.loadFromFile("assets/ui/buttons/menu_clicked.png")
      ) {
    std::cout << "Cannot load one of the menu buttons texture\n";
  }
}

void ButtonsService::loadStartButtonsTextures() {
  if (
      !startButtonTexture.loadFromFile("assets/ui/buttons/start.png") ||
      !startButtonClickedTexture.loadFromFile("assets/ui/buttons/start_clicked.png")
      ) {
    std::cout << "Cannot load one of the start buttons texture\n";
  }
}

void ButtonsService::loadInstructionButtonsTextures() {
  if (
      !instructionButtonTexture.loadFromFile("assets/ui/buttons/instruction.png") ||
      !instructionButtonClickedTexture.loadFromFile("assets/ui/buttons/instruction_clicked.png")
      ) {
    std::cout << "Cannot load one of the instruction buttons texture\n";
  }
}

void ButtonsService::loadExitButtonsTextures() {
  if (
      !exitButtonTexture.loadFromFile("assets/ui/buttons/exit.png") ||
      !exitButtonClickedTexture.loadFromFile("assets/ui/buttons/exit_clicked.png")
      ) {
    std::cout << "Cannot load one of the exit buttons texture\n";
  }
}

void ButtonsService::loadReturnButtonsTextures() {
  if (
      !returnButtonTexture.loadFromFile("assets/ui/buttons/return.png") ||
      !returnButtonClickedTexture.loadFromFile("assets/ui/buttons/return_clicked.png")
      ) {
    std::cout << "Cannot load one of the return buttons texture \n";
  }
}

void ButtonsService::loadRestartButtonsSprites() {
  restartButtonSprite.setTexture(restartButtonTexture);
  restartButtonClickedSprite.setTexture(restartButtonClickedTexture);
}

void ButtonsService::loadMenuButtonsSprites() {
  menuButtonSprite.setTexture(menuButtonTexture);
  menuButtonClickedSprite.setTexture(menuButtonClickedTexture);
}

void ButtonsService::loadStartButtonsSprites() {
  startButtonSprite.setTexture(startButtonTexture);
  startButtonClickedSprite.setTexture(startButtonClickedTexture);
}

void ButtonsService::loadInstructionButtonsSprites() {
  instructionButtonSprite.setTexture(instructionButtonTexture);
  instructionButtonClickedSprite.setTexture(instructionButtonClickedTexture);
}

void ButtonsService::loadExitButtonsSprites() {
  exitButtonSprite.setTexture(exitButtonTexture);
  exitButtonClickedSprite.setTexture(exitButtonClickedTexture);
}

void ButtonsService::loadReturnButtonsSprites() {
  returnButtonSprite.setTexture(returnButtonTexture);
  returnButtonClickedSprite.setTexture(returnButtonClickedTexture);
}
