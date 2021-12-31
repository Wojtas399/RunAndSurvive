#ifndef R_S_GAME_PARAMS_H
#define R_S_GAME_PARAMS_H

class GameParams {
private:
  float initialMapSpeed = 1.6;
  float initialBackgroundStartPosition = 2294;
  float initialGroundStartPosition = 1404;
  float initialRobotLeftVelocityX = -3.5;
  int initialZombieGeneratingTime = 4000;
  float initialZombieDefaultLeftVelocityX = -2.5;
  float initialZombieDefaultRightVelocityX = -0.5;
  float initialZombieStartXPosition = 1700;
  float initialBulletLeftVelocityX = -8.5;

public:
  bool isGameStarted = false;
  float mapSpeed = initialMapSpeed;
  float backgroundStartPosition = initialBackgroundStartPosition;
  float groundStartPosition = initialGroundStartPosition;
  float robotLeftVelocityX = initialRobotLeftVelocityX;
  int zombieGeneratingTime = initialZombieGeneratingTime;
  float zombieDefaultLeftVelocityX = initialZombieDefaultLeftVelocityX;
  float zombieDefaultRightVelocityX = initialZombieDefaultRightVelocityX;
  float zombieStartXPosition = initialZombieStartXPosition;
  float bulletLeftVelocityX = initialBulletLeftVelocityX;

  void setInitialValues();
};


#endif //R_S_GAME_PARAMS_H
