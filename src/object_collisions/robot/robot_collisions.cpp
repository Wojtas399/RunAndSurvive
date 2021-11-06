#include "robot_collisions.h"

bool RobotCollisions::isCollisionWithGroundElement(float widthReduction, float heightReduction) {
  sf::Vector2<float> robotPosition = robot.getPosition();
  float robotWidth = robot.spriteWidth - widthReduction;
  float robotHeight = robot.spriteHeight - heightReduction;
  float robotRightBorder = robot.isReversed ? robotPosition.x - widthReduction : robotPosition.x + robotWidth;
  float robotLeftBorder = robot.isReversed ? robotPosition.x - robotWidth : robotPosition.x + widthReduction;
  for (MapElement &groundElement: groundElements) {
    sf::Vector2<float> elementPosition = groundElement.getSpritePosition();
    auto elementWidth = static_cast<float>(groundElement.width);
    if (
        groundElement.type == MapElementType::groundBlock ||
        groundElement.type == MapElementType::groundWall
        ) {
      if (
          robotRightBorder > elementPosition.x &&
          robotLeftBorder < elementPosition.x + elementWidth &&
          robotPosition.y + robotHeight > elementPosition.y
          ) {
        return true;
      }
    } else if (groundElement.type == MapElementType::groundStairs) {
      if (
          (
              robotRightBorder > elementPosition.x &&
              robotLeftBorder < elementPosition.x + 128 &&
              robotPosition.y + robotHeight > elementPosition.y + 128
          ) ||
          (
              robotRightBorder > elementPosition.x + 128 &&
              robotLeftBorder < elementPosition.x + 256 &&
              robotPosition.y + robotHeight > elementPosition.y + 64
          ) ||
          (
              robotRightBorder > elementPosition.x + 256 &&
              robotLeftBorder < elementPosition.x + elementWidth &&
              robotPosition.y + robotHeight > elementPosition.y
          )
          ) {
        return true;
      }
    }
  }
  return false;
}

bool RobotCollisions::isCollisionWithAirElement(float widthReduction, float topReduction, float bottomReduction) {
  sf::Vector2<float> robotPosition = robot.getPosition();
  float robotWidth = robot.spriteWidth - widthReduction;
  float robotHeight = robot.spriteHeight - bottomReduction;
  float robotRightBorder = robot.isReversed ? robotPosition.x - widthReduction : robotPosition.x + robotWidth;
  float robotLeftBorder = robot.isReversed ? robotPosition.x - robotWidth : robotPosition.x + widthReduction;
  for (MapElement &airElement: airElements) {
    sf::Vector2<float> elementPosition = airElement.getSpritePosition();
    auto elementWidth = static_cast<float>(airElement.width);
    auto elementHeight = static_cast<float>(airElement.height);
    if (airElement.type == MapElementType::airGround) {
      if (
          robotRightBorder > elementPosition.x &&
          robotLeftBorder < elementPosition.x + elementWidth &&
          robotPosition.y + robotHeight > elementPosition.y &&
          robotPosition.y + topReduction < elementPosition.y + elementHeight
          ) {
        return true;
      }
    } else if (airElement.type == MapElementType::airDoubleLevel) {
      if (
          (
              robotRightBorder > elementPosition.x &&
              robotLeftBorder < elementPosition.x + 128 &&
              robotPosition.y + robotHeight > elementPosition.y + 64 &&
              robotPosition.y + topReduction < elementPosition.y + elementHeight
          ) ||
          (
              robotRightBorder > elementPosition.x + 128 &&
              robotLeftBorder < elementPosition.x + 160 &&
              robotPosition.y + robotHeight > elementPosition.y &&
              robotPosition.y + topReduction < elementPosition.y + elementHeight
          ) ||
          (
              robotRightBorder > elementPosition.x + 128 &&
              robotLeftBorder < elementPosition.x + elementWidth &&
              robotPosition.y + robotHeight > elementPosition.y &&
              robotPosition.y + topReduction < elementPosition.y + 32
          )
          ) {
        return true;
      }
    } else if (airElement.type == MapElementType::airDoubleLevelReversed) {
      if (
          (
              robotRightBorder > elementPosition.x &&
              robotRightBorder < elementPosition.x + 128 &&
              robotPosition.y + robotHeight > elementPosition.y &&
              robotPosition.y + topReduction < elementPosition.y + 32
          ) ||
          (
              robotRightBorder > elementPosition.x + 128 &&
              robotLeftBorder < elementPosition.x + 160 &&
              robotPosition.y + robotHeight > elementPosition.y &&
              robotPosition.y + topReduction < elementPosition.y + elementHeight
          ) ||
          (
              robotRightBorder > elementPosition.x + 160 &&
              robotLeftBorder < elementPosition.x + elementWidth &&
              robotPosition.y + robotHeight > elementPosition.y + 64 &&
              robotPosition.y + topReduction < elementPosition.y + elementHeight
          )
          ) {
        return true;
      }
    }
  }
  return false;
}
