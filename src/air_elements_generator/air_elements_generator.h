#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>
#include <random>
#include "../constants.h"

#ifndef R_S_AIR_ELEMENTS_GENERATOR_H
#define R_S_AIR_ELEMENTS_GENERATOR_H

class AirElementsGenerator {
private:
  sf::Texture simpleGroundTexture;
  sf::Texture doubleLevelGroundTexture;
  sf::Texture doubleLevelGroundReversedTexture;
  sf::Sprite simpleGroundSpr;
  sf::Sprite doubleLevelGroundSpr;
  sf::Sprite doubleLevelGroundReversedSpr;
  sf::RenderWindow &window;
  std::mt19937 &random_generator;
  std::chrono::steady_clock::time_point timerStart, timerEnd;

  void setSprite();

  void generateNewElement();

  void setNewElementPosition(sf::Sprite &element);

public:
  AirElementsGenerator(
      sf::RenderWindow &window,
      std::mt19937 &random_generator
  ) : window(window), random_generator(random_generator) {}

  std::vector<sf::Sprite> airElements;

  void loadTexture();

  void move();

  void draw();
};

#endif //R_S_AIR_ELEMENTS_GENERATOR_H
