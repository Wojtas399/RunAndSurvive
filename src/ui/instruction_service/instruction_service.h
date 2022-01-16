#ifndef R_S_INSTRUCTION_SERVICE_H
#define R_S_INSTRUCTION_SERVICE_H

#include <SFML/Graphics.hpp>
#include "iostream"
#include "../buttons_service/buttons_service.h"

class InstructionService {
private:
  ButtonsService &buttonsService;
  sf::Texture instructionScreenTexture;
  sf::Sprite instructionScreenSprite;

  void setSprite();

public:
  explicit InstructionService(ButtonsService &buttonsService) : buttonsService(buttonsService) {}

  void loadTexture();

  void draw(sf::RenderWindow &window);
};


#endif //R_S_INSTRUCTION_SERVICE_H
