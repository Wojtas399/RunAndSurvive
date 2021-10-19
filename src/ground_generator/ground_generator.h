#include <SFML/Graphics.hpp>
#include <utility>
#include "../air_elements_generator/air_elements_generator.h"
#include "../ground_elements_generator/ground_elements_generator.h"

#ifndef R_S_GROUND_H
#define R_S_GROUND_H

class GroundGenerator {
private:
  sf::Texture groundTexture;
  sf::Sprite groundSpr1;
  sf::Sprite groundSpr2;
  AirElementsGenerator &airElementsGenerator;
  GroundElementsGenerator &groundElementsGenerator;

  void setSprites();

  static void setNewPosition(sf::Sprite &sprite) ;

public:
  GroundGenerator(
      AirElementsGenerator &airElementsGenerator,
      GroundElementsGenerator &groundElementsGenerator
      ): airElementsGenerator(airElementsGenerator), groundElementsGenerator(groundElementsGenerator) {}

  void load();

  void draw(sf::RenderWindow &window);

  void move();
};

#endif //R_S_GROUND_H
