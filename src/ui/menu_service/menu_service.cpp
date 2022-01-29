#include "menu_service.h"

void MenuService::loadTexture() {
  if (!menuScreenTexture.loadFromFile("assets/ui/menu_screen.png")) {
    std::cout << "Cannot load menu screen texture\n";
  }
  menuScreenSprite.setTexture(menuScreenTexture);
  setButtons();
}

void MenuService::draw(sf::RenderWindow &window) {
  window.draw(menuScreenSprite);
  float y = 280;
  for (sf::Sprite button : buttons) {
    button.setPosition(570, y);
    window.draw(button);
    y += 100;
  }
}

void MenuService::moveUp() {
  selectedButton = selectedButton == 0 ? 2 : selectedButton - 1;
  setButtons();
}

void MenuService::moveDown() {
  selectedButton = selectedButton == 2 ? 0 : selectedButton + 1;
  setButtons();
}

void MenuService::setButtons() {
  buttons.clear();
  if (selectedButton == 0) {
    buttons.insert(buttons.begin(), {
      buttonsService.startButtonClickedSprite,
      buttonsService.instructionButtonSprite,
      buttonsService.exitButtonSprite,
    });
  } else if (selectedButton == 1) {
    buttons.insert(buttons.begin(), {
      buttonsService.startButtonSprite,
      buttonsService.instructionButtonClickedSprite,
      buttonsService.exitButtonSprite,
    });
  } else if (selectedButton == 2) {
    buttons.insert(buttons.begin(), {
        buttonsService.startButtonSprite,
        buttonsService.instructionButtonSprite,
        buttonsService.exitButtonClickedSprite,
    });
  }
}
