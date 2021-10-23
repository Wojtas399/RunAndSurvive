#ifndef R_S_AIR_ELEMENT_H
#define R_S_AIR_ELEMENT_H

#include <SFML/Graphics.hpp>

enum MapElementType {
  airDoubleLevel,
  airDoubleLevelReversed,
  airGround,
  groundBlock,
  groundWall,
  groundStairs,
};

class MapElement {
private:
  void setSize();

public:
  MapElement(MapElementType elementType, sf::Sprite sprite) {
    this->type = elementType;
    this->sprite = std::move(sprite);
    setSize();
  }

  MapElementType type;
  sf::Sprite sprite;
  int width = 0;
  int height = 0;

  sf::Vector2<float> getSpritePosition();
};

#endif //R_S_AIR_ELEMENT_H
