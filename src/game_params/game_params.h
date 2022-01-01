#ifndef R_S_GAME_PARAMS_H
#define R_S_GAME_PARAMS_H

class GameParams {
private:
  float initialMapSpeed = 1.6;
  float initialRobotLeftVelocityX = -3.5;
  int initialZombieGeneratingTime = 4000;
  float initialZombieDefaultLeftVelocityX = -2.5;
  float initialZombieDefaultRightVelocityX = -0.5;
  float initialZombieStartXPosition = 1700;
  float initialBulletLeftVelocityX = -8.5;

public:
  bool isGameStarted = false;
  float mapSpeed = initialMapSpeed;
  float robotLeftVelocityX = initialRobotLeftVelocityX;
  int zombieGeneratingTime = initialZombieGeneratingTime;
  float zombieDefaultLeftVelocityX = initialZombieDefaultLeftVelocityX;
  float zombieDefaultRightVelocityX = initialZombieDefaultRightVelocityX;
  float zombieStartXPosition = initialZombieStartXPosition;
  float bulletLeftVelocityX = initialBulletLeftVelocityX;

  void setInitialValues();
};


#endif //R_S_GAME_PARAMS_H
