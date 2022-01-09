#ifndef R_S_END_GAME_SERVICE_H
#define R_S_END_GAME_SERVICE_H

#include <SFML/Graphics.hpp>
#include "iostream"
#include "../buttons_service/buttons_service.h"

class EndGameService {
private:
  ButtonsService &buttonsService;
  sf::Texture resultScreenTexture;
  sf::Sprite resultScreenSprite;
  std::vector<sf::Sprite> buttons;

public:
  explicit EndGameService(ButtonsService &buttonsService) : buttonsService(buttonsService) {}

  int selectedButton = 0;

  void loadTexture();

  void draw(const std::vector<sf::Sprite> &pointsSprites, sf::RenderWindow &window);

  void selectButton(int buttonIndex);
};


#endif //R_S_END_GAME_SERVICE_H
