#ifndef R_S_UI_CONTROLLER_H
#define R_S_UI_CONTROLLER_H

#include <SFML/Graphics.hpp>
#include "life_service/life_service.h"
#include "points_service/points_service.h"
#include "zobie_points_service/zombie_points_service.h"
#include "end_game_service/end_game_service.h"

class UIController {
private:
  LifeService &lifeService;
  PointsService &pointsService;
  ZombiePointsService &zombiePointsService;
  EndGameService &endGameService;
  ButtonsService &buttonsService;

public:
  UIController(
      LifeService &lifeService,
      PointsService &pointsService,
      ZombiePointsService &zombiePointsService,
      EndGameService &endGameService,
      ButtonsService &buttonsService
  ) : lifeService(lifeService),
      pointsService(pointsService),
      zombiePointsService(zombiePointsService),
      endGameService(endGameService),
      buttonsService(buttonsService) {}

  void loadTextures();

  int endScreenKeyController();

  void move();

  void draw(sf::RenderWindow &window);

  void setInitialParams();

  void addPointForSecond();

  void addPointsForZombie(float zombieXPosition, float zombieYPosition);

  void displayResult(sf::RenderWindow &window);
};


#endif //R_S_UI_CONTROLLER_H
