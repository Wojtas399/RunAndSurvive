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

bool RobotCollisions::isCollisionWithAirElement(float widthReduction, float heightReduction) {
  sf::Vector2<float> robotPosition = robot.getPosition();
  float robotWidth = robot.spriteWidth - widthReduction;
  float robotHeight = robot.spriteHeight - heightReduction;
  for (MapElement &airElement: airElements) {
    sf::Vector2<float> elementPosition = airElement.getSpritePosition();
    auto elementWidth = static_cast<float>(airElement.width);
    auto elementHeight = static_cast<float>(airElement.height);
    if (airElement.type == MapElementType::airGround) {
      if (
          robotPosition.x + robotWidth > elementPosition.x &&
          robotPosition.x + widthReduction < elementPosition.x + elementWidth &&
          robotPosition.y + robotHeight > elementPosition.y &&
          robotPosition.y + heightReduction < elementPosition.y + elementHeight
          ) {
        return true;
      }
    } else if (airElement.type == MapElementType::airDoubleLevel) {
      if (
          (
              robotPosition.x + robotWidth > elementPosition.x &&
              robotPosition.x + widthReduction < elementPosition.x + 128 &&
              robotPosition.y + robotHeight > elementPosition.y + 64 &&
              robotPosition.y + heightReduction < elementPosition.y + elementHeight
          ) ||
          (
              robotPosition.x + robotWidth > elementPosition.x + 128 &&
              robotPosition.x + widthReduction < elementPosition.x + elementWidth &&
              robotPosition.y + robotHeight > elementPosition.y &&
              robotPosition.y + heightReduction < elementPosition.y + 32
          )
          ) {
        return true;
      }
    } else if (airElement.type == MapElementType::airDoubleLevelReversed) {
      if (
          (
              robotPosition.x + robotWidth > elementPosition.x &&
              robotPosition.x + widthReduction < elementPosition.x + 160 &&
              robotPosition.y + robotHeight > elementPosition.y &&
              robotPosition.y + heightReduction < elementPosition.y + 32
          ) ||
          (
              robotPosition.x + robotWidth > elementPosition.x + 160 &&
              robotPosition.x + widthReduction < elementPosition.x + elementWidth &&
              robotPosition.y + robotHeight > elementPosition.y + 64 &&
              robotPosition.y + heightReduction < elementPosition.y + elementHeight
          )
          ) {
        return true;
      }
    }
  }
  return false;
}
