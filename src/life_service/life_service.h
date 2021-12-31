#ifndef R_S_LIFE_SERVICE_H
#define R_S_LIFE_SERVICE_H

#include <SFML/Graphics.hpp>
#include "iostream"

class LifeService {
private:
  sf::Texture lifeTexture;
  int initialLifeAmount = 5;
  std::vector<sf::Sprite> lifeSprites;

  void loadSprites();

public:
  int lifeAmount = initialLifeAmount;

  void loadTexture();

  void setInitialLifeAmount();

  void draw(sf::RenderWindow &window);

  void subtractLife();
};


#endif //R_S_LIFE_SERVICE_H
