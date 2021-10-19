#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>
#include <random>
#include "../constants.h"

#ifndef R_S_GROUND_ELEMENTS_GENERATOR_H
#define R_S_GROUND_ELEMENTS_GENERATOR_H

class GroundElementsGenerator {
private:
  sf::Texture simpleBlockTexture;
  sf::Texture stairsTexture;
  sf::Texture simpleWallTexture;
  sf::Sprite simpleBlockSpr;
  sf::Sprite stairsSpr;
  sf::Sprite simpleWallSpr;
  sf::RenderWindow &window;
  int &maxElementsAmount;
  std::mt19937 &random_generator;
  std::chrono::steady_clock::time_point timerStart, timerEnd;

  void setSprite();

  void generateNewElement();

  void setNewElementPosition(sf::Sprite &element);

public:
  GroundElementsGenerator(
      sf::RenderWindow &window,
      int &maxElementsAmount,
      std::mt19937 &random_generator
  ) : window(window), maxElementsAmount(maxElementsAmount), random_generator(random_generator) {}

  std::vector<sf::Sprite> groundElements;

  void loadTexture();

  void move();

  void draw();
};

#endif //R_S_GROUND_ELEMENTS_GENERATOR_H
