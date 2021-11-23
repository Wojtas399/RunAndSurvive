#ifndef R_S_ZOMBIE_TEXTURES_H
#define R_S_ZOMBIE_TEXTURES_H

#include <SFML/Graphics.hpp>
#include <iostream>

class ZombieTextures {
private:
  sf::Texture z1Run1Texture;
  sf::Texture z1Run2Texture;
  sf::Texture z1Run3Texture;
  sf::Texture z1Run4Texture;
  sf::Texture z1Run5Texture;
  sf::Texture z1Run6Texture;
  sf::Texture z2Run1Texture;
  sf::Texture z2Run2Texture;
  sf::Texture z2Run3Texture;
  sf::Texture z2Run4Texture;
  sf::Texture z2Run5Texture;
  sf::Texture z2Run6Texture;
  sf::Texture z3Run1Texture;
  sf::Texture z3Run2Texture;
  sf::Texture z3Run3Texture;
  sf::Texture z3Run4Texture;
  sf::Texture z3Run5Texture;
  sf::Texture z3Run6Texture;

  void loadZ1Textures();

  void loadZ2Textures();

  void loadZ3Textures();

  void loadZ1RunTextures();

  void loadZ2RunTextures();

  void loadZ3RunTextures();

public:
  std::vector<sf::Texture> zombie1RunTextures;
  std::vector<sf::Texture> zombie2RunTextures;
  std::vector<sf::Texture> zombie3RunTextures;

  void loadTextures();

};


#endif //R_S_ZOMBIE_TEXTURES_H
