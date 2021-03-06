#include "end_game_service.h"

void EndGameService::loadTexture() {
  if (!resultScreenTexture.loadFromFile("assets/ui/end_game_result.png")) {
    std::cout << "Cannot load result screen texture\n";
  }
  resultScreenSprite.setTexture(resultScreenTexture);
  setButtons();
}

void EndGameService::draw(const std::vector<sf::Sprite> &pointsSprites, sf::RenderWindow &window) {
  window.draw(resultScreenSprite);
  int digitsAmount = static_cast<int>(pointsSprites.size());
  auto x = static_cast<float>(650 - (digitsAmount % 2 == 1 ? 61 * (digitsAmount / 2) : 30 * (digitsAmount / 2)));
  for (sf::Sprite point : pointsSprites) {
    point.setScale(3, 3);
    point.setPosition(x, 315);
    window.draw(point);
    x += 60;
  }
  x = 425;
  for (sf::Sprite button : buttons) {
    button.setPosition(x, 475);
    window.draw(button);
    x += 300;
  }
}

void EndGameService::moveLeft() {
  selectedButton = selectedButton == 0 ? 1 : 0;
  setButtons();
}

void EndGameService::moveRight() {
  selectedButton = selectedButton == 1 ? 0 : 1;
  setButtons();
}

void EndGameService::setButtons() {
  buttons.clear();
  if (selectedButton == 0) {
    buttons.insert(buttons.begin(), {
      buttonsService.restartButtonClickedSprite,
      buttonsService.menuButtonSprite,
    });
  } else if (selectedButton == 1) {
    buttons.insert(buttons.begin(), {
      buttonsService.restartButtonSprite,
      buttonsService.menuButtonClickedSprite,
    });
  }
}
