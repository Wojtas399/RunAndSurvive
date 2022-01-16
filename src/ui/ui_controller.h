#ifndef R_S_UI_CONTROLLER_H
#define R_S_UI_CONTROLLER_H

#include <SFML/Graphics.hpp>
#include "life_service/life_service.h"
#include "points_service/points_service.h"
#include "zobie_points_service/zombie_points_service.h"
#include "end_game_service/end_game_service.h"
#include "menu_service/menu_service.h"
#include "instruction_service/instruction_service.h"

class UIController {
private:
  LifeService &lifeService;
  PointsService &pointsService;
  ZombiePointsService &zombiePointsService;
  MenuService &menuService;
  InstructionService &instructionService;
  EndGameService &endGameService;
  ButtonsService &buttonsService;

public:
  UIController(
      LifeService &lifeService,
      PointsService &pointsService,
      ZombiePointsService &zombiePointsService,
      MenuService &menuService,
      InstructionService &instructionService,
      EndGameService &endGameService,
      ButtonsService &buttonsService
  ) : lifeService(lifeService),
      pointsService(pointsService),
      zombiePointsService(zombiePointsService),
      menuService(menuService),
      instructionService(instructionService),
      endGameService(endGameService),
      buttonsService(buttonsService) {}

  void loadTextures();

  int menuScreenKeyController();

  int instructionScreenKeyController();

  int endScreenKeyController();

  void move();

  void draw(sf::RenderWindow &window);

  void setInitialParams();

  void addPointForSecond();

  void addPointsForZombie(float zombieXPosition, float zombieYPosition);

  void displayMenu(sf::RenderWindow &window);

  void displayInstruction(sf::RenderWindow &window);

  void displayResult(sf::RenderWindow &window);
};


#endif //R_S_UI_CONTROLLER_H
