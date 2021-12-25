#ifndef R_S_LIFE_SERVICE_H
#define R_S_LIFE_SERVICE_H

#include <SFML/Graphics.hpp>
#include "iostream"

class LifeService {
private:
  sf::Texture lifeTexture;
  std::vector<sf::Sprite> lifeSprites;

  void loadSprites();

public:
  int lifeAmount = 5;

  void loadTexture();

  void draw(sf::RenderWindow &window);

  void subtractLife();
};


#endif //R_S_LIFE_SERVICE_H
