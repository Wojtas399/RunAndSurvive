#include "map_elements_collisions.h"

bool MapElementsCollisions::isCollisionWithGroundElement(
    float x,
    float y,
    float width,
    float height,
    bool isReversed,
    float leftReduction,
    float rightReduction,
    float heightReduction
) {
  float spriteWidth = isReversed ? width - leftReduction : width - rightReduction;
  float spriteHeight = height - heightReduction;
  float spriteRightBorder = isReversed ? x - rightReduction : x + spriteWidth;
  float spriteLeftBorder = isReversed ? x - spriteWidth : x + leftReduction;
  for (MapElement &groundElement: groundElements) {
    sf::Vector2<float> elementPosition = groundElement.getSpritePosition();
    auto elementWidth = static_cast<float>(groundElement.width);
    if (
        groundElement.type == MapElementType::groundBlock ||
        groundElement.type == MapElementType::groundBlockDouble ||
        groundElement.type == MapElementType::groundBlockTriple ||
        groundElement.type == MapElementType::groundWall
        ) {
      if (
          spriteRightBorder > elementPosition.x &&
          spriteLeftBorder < elementPosition.x + elementWidth &&
          y + spriteHeight > elementPosition.y
          ) {
        return true;
      }
    } else if (groundElement.type == MapElementType::groundStairs) {
      if (
          (
              spriteRightBorder > elementPosition.x &&
              spriteLeftBorder < elementPosition.x + 128 &&
              y + spriteHeight > elementPosition.y + 128
          ) ||
          (
              spriteRightBorder > elementPosition.x + 128 &&
              spriteLeftBorder < elementPosition.x + 256 &&
              y + spriteHeight > elementPosition.y + 64
          ) ||
          (
              spriteRightBorder > elementPosition.x + 256 &&
              spriteLeftBorder < elementPosition.x + elementWidth &&
              y + spriteHeight > elementPosition.y
          )
          ) {
        return true;
      }
    }
  }
  return false;
}

bool MapElementsCollisions::isCollisionWithAirElement(
    float x,
    float y,
    float width,
    float height,
    bool isReversed,
    float leftReduction,
    float rightReduction,
    float topReduction,
    float bottomReduction
) {
  float spriteWidth = isReversed ? width - leftReduction : width - rightReduction;
  float spriteHeight = height - bottomReduction;
  float spriteRightBorder = isReversed ? x - rightReduction : x + spriteWidth;
  float spriteLeftBorder = isReversed ? x - spriteWidth : x + leftReduction;
  for (MapElement &airElement: airElements) {
    sf::Vector2<float> elementPosition = airElement.getSpritePosition();
    auto elementWidth = static_cast<float>(airElement.width);
    auto elementHeight = static_cast<float>(airElement.height);
    if (airElement.type == MapElementType::airGround1 || airElement.type == MapElementType::airGround2) {
      if (
          spriteRightBorder > elementPosition.x &&
          spriteLeftBorder < elementPosition.x + elementWidth &&
          y + spriteHeight > elementPosition.y &&
          y + topReduction < elementPosition.y + elementHeight
          ) {
        return true;
      }
    } else if (airElement.type == MapElementType::airDoubleLevel) {
      if (
          (
              spriteRightBorder > elementPosition.x &&
              spriteLeftBorder < elementPosition.x + 128 &&
              y + spriteHeight > elementPosition.y + 80 &&
              y + topReduction < elementPosition.y + elementHeight
          ) ||
          (
              spriteRightBorder > elementPosition.x + 128 &&
              spriteLeftBorder < elementPosition.x + 160 &&
              y + spriteHeight > elementPosition.y &&
              y + topReduction < elementPosition.y + elementHeight
          ) ||
          (
              spriteRightBorder > elementPosition.x + 128 &&
              spriteLeftBorder < elementPosition.x + elementWidth &&
              y + spriteHeight > elementPosition.y &&
              y + topReduction < elementPosition.y + 16
          )
          ) {
        return true;
      }
    } else if (airElement.type == MapElementType::airDoubleLevelReversed) {
      if (
          (
              spriteRightBorder > elementPosition.x &&
              spriteRightBorder < elementPosition.x + 128 &&
              y + spriteHeight > elementPosition.y &&
              y + topReduction < elementPosition.y + 16
          ) ||
          (
              spriteRightBorder > elementPosition.x + 128 &&
              spriteLeftBorder < elementPosition.x + 160 &&
              y + spriteHeight > elementPosition.y &&
              y + topReduction < elementPosition.y + elementHeight
          ) ||
          (
              spriteRightBorder > elementPosition.x + 160 &&
              spriteLeftBorder < elementPosition.x + elementWidth &&
              y + spriteHeight > elementPosition.y + 80 &&
              y + topReduction < elementPosition.y + elementHeight
          )
          ) {
        return true;
      }
    }
  }
  return false;
}
