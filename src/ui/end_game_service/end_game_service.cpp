#include "end_game_service.h"

void EndGameService::loadTexture() {
  if (!resultScreenTexture.loadFromFile("assets/ui/end_game_result.png")) {
    std::cout << "Cannot load result screen texture\n";
  }
  resultScreenSprite.setTexture(resultScreenTexture);
}

void EndGameService::draw(const std::vector<sf::Sprite> &pointsSprites, sf::RenderWindow &window) {
  window.draw(resultScreenSprite);
  int digitsAmount = static_cast<int>(pointsSprites.size());
  auto x = static_cast<float>(650 - (digitsAmount % 2 == 1 ? 50 * (digitsAmount / 2) : 24 * (digitsAmount / 2)));
  for (sf::Sprite point : pointsSprites) {
    point.setScale(2.6, 2.6);
    point.setPosition(x, 315);
    window.draw(point);
    x += 60;
  }
}
