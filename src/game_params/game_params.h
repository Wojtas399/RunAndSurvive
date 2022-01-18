#ifndef R_S_GAME_PARAMS_H
#define R_S_GAME_PARAMS_H

#include <SFML/Graphics.hpp>

class GameParams {
private:
  float initialMapSpeed = 1.6;
  float initialRobotLeftVelocityX = -3.5;
  int initialZombieGeneratingTime = 4000;
  float initialZombieDefaultLeftVelocityX = -2.5;
  float initialZombieDefaultRightVelocityX = -0.5;
  float initialZombieStartXPosition = 1700;
  float initialBulletLeftVelocityX = -8.5;
  bool initialIsBulletBonusOn = false;

public:
  bool isGameStarted = false;
  float mapSpeed = initialMapSpeed;
  float robotLeftVelocityX = initialRobotLeftVelocityX;
  int zombieGeneratingTime = initialZombieGeneratingTime;
  float zombieDefaultLeftVelocityX = initialZombieDefaultLeftVelocityX;
  float zombieDefaultRightVelocityX = initialZombieDefaultRightVelocityX;
  float zombieStartXPosition = initialZombieStartXPosition;
  float bulletLeftVelocityX = initialBulletLeftVelocityX;
  bool isBulletBonusOn = initialIsBulletBonusOn;
  sf::Clock bulletBonusClock;

  void setInitialValues();
};


#endif //R_S_GAME_PARAMS_H
