#ifndef R_S_BONUS_SERVICE_H
#define R_S_BONUS_SERVICE_H

#include <SFML/Graphics.hpp>
#include "iostream"

class BonusService {
private:
  sf::Texture bonusTexture;
  sf::Sprite bonusSprite;

  void setSprite();

public:
  void loadTexture();

  void draw(sf::RenderWindow &window);
};


#endif //R_S_BONUS_SERVICE_H
