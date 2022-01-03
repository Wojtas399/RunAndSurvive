#ifndef R_S_LIFE_SERVICE_H
#define R_S_LIFE_SERVICE_H

#include <SFML/Graphics.hpp>
#include "iostream"
#include "../../models/anim/anim.h"

class LifeService {
private:
  sf::Texture heartTexture;
  int initialLivesAmount = 5;
  std::vector<Anim> lives;

  void loadSprites();

  void nextAnimStep(Anim &life);

  void deleteLastLifeSprite();

public:
  int livesAmount = initialLivesAmount;

  void loadTexture();

  void setInitialLivesAmount();

  void move();

  void draw(sf::RenderWindow &window);

  void subtractLife();
};


#endif //R_S_LIFE_SERVICE_H
