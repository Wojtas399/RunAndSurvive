#include "instruction_service.h"

void InstructionService::loadTexture() {
  if (!instructionScreenTexture.loadFromFile("assets/ui/instruction_screen.png")) {
    std::cout << "Cannot load instruction screen texture\n";
  }
  setSprite();
}

void InstructionService::draw(sf::RenderWindow &window) {
  window.draw(instructionScreenSprite);
  window.draw(buttonsService.returnButtonClickedSprite);
}

void InstructionService::setSprite() {
  instructionScreenSprite.setTexture(instructionScreenTexture);
  buttonsService.returnButtonClickedSprite.setPosition(570, 575);
}
