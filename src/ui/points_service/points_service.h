#ifndef R_S_POINTS_SERVICE_H
#define R_S_POINTS_SERVICE_H

#include "iostream"
#include <SFML/Graphics.hpp>

class PointsService {
private:
  sf::Texture number0Texture;
  sf::Texture number1Texture;
  sf::Texture number2Texture;
  sf::Texture number3Texture;
  sf::Texture number4Texture;
  sf::Texture number5Texture;
  sf::Texture number6Texture;
  sf::Texture number7Texture;
  sf::Texture number8Texture;
  sf::Texture number9Texture;

  void loadSprites();

  sf::Sprite createPointSprite(int textureCounter, float xPosition);

public:
  std::vector<sf::Texture> pointTextures;
  int points = 0;
  std::vector<sf::Sprite> pointSprites;

  void loadTextures();

  void resetPoints();

  void draw(sf::RenderWindow &window);

  void addPointForSecond();

  void addPointsForZombie();
};


#endif //R_S_POINTS_SERVICE_H
