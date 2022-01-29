#ifndef R_S_MENU_SERVICE_H
#define R_S_MENU_SERVICE_H

#include <SFML/Graphics.hpp>
#include "iostream"
#include "../buttons_service/buttons_service.h"

class MenuService {
private:
  ButtonsService &buttonsService;
  sf::Texture menuScreenTexture;
  sf::Sprite menuScreenSprite;
  std::vector<sf::Sprite> buttons;

  void setButtons();

public:
  explicit MenuService(ButtonsService &buttonsService) : buttonsService(buttonsService) {}

  int selectedButton = 0;

  void loadTexture();

  void draw(sf::RenderWindow &window);

  void moveUp();

  void moveDown();
};


#endif //R_S_MENU_SERVICE_H
