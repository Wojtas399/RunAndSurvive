#include "robot_collisions.h"

bool RobotCollisions::isCollisionWithGroundElement(float widthReduction, float heightReduction) {
  sf::Vector2<float> robotPosition = robot.getPosition();
  float robotWidth = robot.spriteWidth - widthReduction;
  float robotHeight = robot.spriteHeight - heightReduction;
  for (MapElement &groundElement: groundElements) {
    sf::Vector2<float> elementPosition = groundElement.getSpritePosition();
    auto elementWidth = static_cast<float>(groundElement.width);
    if (
        groundElement.type == MapElementType::groundBlock ||
        groundElement.type == MapElementType::groundWall
        ) {
      if (
          robotPosition.x + robotWidth > elementPosition.x &&
          robotPosition.x + widthReduction < elementPosition.x + elementWidth &&
          robotPosition.y + robotHeight > elementPosition.y
          ) {
        return true;
      }
    } else if (groundElement.type == MapElementType::groundStairs) {
      if (
          (
              robotPosition.x + robotWidth > elementPosition.x &&
              robotPosition.x + widthReduction < elementPosition.x + 128 &&
              robotPosition.y + robotHeight > elementPosition.y + 128
          ) ||
          (
              robotPosition.x + robotWidth > elementPosition.x + 128 &&
              robotPosition.x + widthReduction < elementPosition.x + 256 &&
              robotPosition.y + robotHeight > elementPosition.y + 64
          ) ||
          (
              robotPosition.x + robotWidth > elementPosition.x + 256 &&
              robotPosition.x + widthReduction < elementPosition.x + elementWidth &&
              robotPosition.y + robotHeight > elementPosition.y
          )
          ) {
        return true;
      }
    }
  }
  return false;
}
