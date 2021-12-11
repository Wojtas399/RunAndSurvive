#ifndef R_S_ROBOT_ZOMBIE_COLLISIONS_H
#define R_S_ROBOT_ZOMBIE_COLLISIONS_H


#include <SFML/Graphics.hpp>
#include "../../models/robot/robot.h"
#include "../../models/zombie/zombie.h"

class RobotZombieCollisions {
public:
  bool isRobotCollisionWithZombie(Robot &robot, Zombie &zombie);
};


#endif //R_S_ROBOT_ZOMBIE_COLLISIONS_H
