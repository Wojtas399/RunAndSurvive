#include "map_element.h"

sf::Vector2<float> MapElement::getSpritePosition() {
  return sprite.getPosition();
}

void MapElement::setSize() {
  switch (type) {
    case MapElementType::airDoubleLevel:
    case MapElementType::airDoubleLevelReversed: {
      width = 288;
      height = 96;
      break;
    }
    case MapElementType::airGround1: {
      width = 160;
      height = 16;
      break;
    }
    case MapElementType::airGround2: {
      width = 158;
      height = 16;
    }
    case MapElementType::groundBlock: {
      width = 128;
      height = 64;
      break;
    }
    case MapElementType::groundWall: {
      width = 32;
      height = 57;
      break;
    }
    case MapElementType::groundStairs: {
      width = 384;
      height = 192;
      break;
    }
  }
}
