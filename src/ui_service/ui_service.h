#ifndef R_S_UI_SERVICE_H
#define R_S_UI_SERVICE_H

#include "iostream"
#include "../game_params/game_params.h"
#include "../models/zombie_points/zombie_points.h"
#include <SFML/Graphics.hpp>

class UIService {
private:
  GameParams &gameParams;
  sf::Texture zombiePointsTexture;
  std::vector<ZombiePoints> zombiePoints;

  void nextZombiePointsAnimStep(ZombiePoints &points) const;

  void deleteZombiePoints(int index);

  void basicZombiePointsMove(ZombiePoints &points) const;

public:
  explicit UIService(GameParams &gameParams) : gameParams(gameParams) {}

  void loadTextures();

  void draw(sf::RenderWindow &window);

  void move();

  void addZombiePoints(float x, float y);
};


#endif //R_S_UI_SERVICE_H
