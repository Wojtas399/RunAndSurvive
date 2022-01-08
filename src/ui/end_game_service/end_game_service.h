#ifndef R_S_END_GAME_SERVICE_H
#define R_S_END_GAME_SERVICE_H

#include <SFML/Graphics.hpp>
#include "iostream"

class EndGameService {
private:
  sf::Texture resultScreenTexture;
  sf::Sprite resultScreenSprite;

public:

  void loadTexture();

  void draw(const std::vector<sf::Sprite> &pointsSprites, sf::RenderWindow &window);
};


#endif //R_S_END_GAME_SERVICE_H
