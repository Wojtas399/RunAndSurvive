#ifndef R_S_ZOMBIE_POINTS_SERVICE_H
#define R_S_ZOMBIE_POINTS_SERVICE_H

#include "iostream"
#include "../../game_params/game_params.h"
#include "../../models/anim/anim.h"
#include <SFML/Graphics.hpp>

class ZombiePointsService {
private:
  GameParams &gameParams;
  sf::Texture zombiePointsTexture;
  std::vector<Anim> zombiePoints;

  void nextZombiePointsAnimStep(Anim &points) const;

  void deleteZombiePoints(int index);

  void basicZombiePointsMove(Anim &points) const;

public:
  explicit ZombiePointsService(GameParams &gameParams) : gameParams(gameParams) {}

  void loadTexture();

  void draw(sf::RenderWindow &window);

  void move();

  void addZombiePoints(float x, float y);
};


#endif //R_S_ZOMBIE_POINTS_SERVICE_H
