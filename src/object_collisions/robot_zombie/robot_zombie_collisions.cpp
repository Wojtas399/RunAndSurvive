#include "robot_zombie_collisions.h"

bool RobotZombieCollisions::isRobotCollisionWithZombie(Robot &robot, Zombie &zombie) {
  sf::Vector2<float> robotPosition = robot.getPosition();
  sf::Vector2<float> zombiePosition = zombie.getPosition();
  float robotHorizontalReduction = 15;
  float robotVerticalReduction = 25;
  float zombieSizeReduction = 10;
  float robotWidth = robot.spriteWidth - robotHorizontalReduction;
  float robotHeight = robot.spriteHeight - robotVerticalReduction;
  float zombieWidth = zombie.width - zombieSizeReduction;
  float zombieHeight = zombie.height - zombieSizeReduction;
  float robotLeftBorder = robot.isReversed ? robotPosition.x - robotWidth : robotPosition.x + robotHorizontalReduction;
  float robotRightBorder = robot.isReversed ? robotPosition.x - robotHorizontalReduction : robotPosition.x + robotWidth;
  float robotBottomBorder = robotPosition.y + robotHeight;
  float robotTopBorder = robotPosition.y + robotVerticalReduction;
  float zombieLeftBorder = zombie.isReversed ? zombiePosition.x - zombieWidth : zombiePosition.x + zombieSizeReduction;
  float zombieRightBorder = zombie.isReversed ? zombiePosition.x - zombieSizeReduction : zombiePosition.x + zombieWidth;
  float zombieBottomBorder = zombiePosition.y + zombieHeight;
  float zombieTopBorder = zombiePosition.y + zombieSizeReduction;

  return robotRightBorder > zombieLeftBorder &&
         robotLeftBorder < zombieRightBorder &&
         robotBottomBorder > zombieTopBorder &&
         robotTopBorder < zombieBottomBorder;
}
