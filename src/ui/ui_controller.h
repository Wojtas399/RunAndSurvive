#ifndef R_S_UI_CONTROLLER_H
#define R_S_UI_CONTROLLER_H

#include <SFML/Graphics.hpp>
#include "life_service/life_service.h"
#include "points_service/points_service.h"
#include "zobie_points_service/zombie_points_service.h"

class UIController {
private:
  LifeService &lifeService;
  PointsService &pointsService;
  ZombiePointsService &zombiePointsService;
public:
  UIController(
      LifeService &lifeService,
      PointsService &pointsService,
      ZombiePointsService &zombiePointsService
  ) : lifeService(lifeService),
      pointsService(pointsService),
      zombiePointsService(zombiePointsService) {}

  void loadTextures();

  void move();

  void draw(sf::RenderWindow &window);

  void setInitialParams();

  void addPointForSecond();

  void addPointsForZombie(float zombieXPosition, float zombieYPosition);
};


#endif //R_S_UI_CONTROLLER_H
