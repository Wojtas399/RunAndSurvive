#include "game_params.h"

void GameParams::setInitialValues() {
  mapSpeed = initialMapSpeed;
  backgroundStartPosition = initialBackgroundStartPosition;
  groundStartPosition = initialGroundStartPosition;
  robotLeftVelocityX = initialRobotLeftVelocityX;
  zombieGeneratingTime = initialZombieGeneratingTime;
  zombieDefaultLeftVelocityX = initialZombieDefaultLeftVelocityX;
  zombieDefaultRightVelocityX = initialZombieDefaultRightVelocityX;
  zombieStartXPosition = initialZombieStartXPosition;
  bulletLeftVelocityX = initialBulletLeftVelocityX;
}
