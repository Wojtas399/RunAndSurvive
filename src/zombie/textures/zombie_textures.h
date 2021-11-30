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
  sf::Texture z1Fall1Texture;
  sf::Texture z1Fall2Texture;
  sf::Texture z1Fall3Texture;
  sf::Texture z1Dead1Texture;
  sf::Texture z1Dead2Texture;
  sf::Texture z1Dead3Texture;
  sf::Texture z1Dead4Texture;
  sf::Texture z1Dead5Texture;
  sf::Texture z1Dead6Texture;
  sf::Texture z1Dead7Texture;
  sf::Texture z1Dead8Texture;
  sf::Texture z2Run1Texture;
  sf::Texture z2Run2Texture;
  sf::Texture z2Run3Texture;
  sf::Texture z2Run4Texture;
  sf::Texture z2Run5Texture;
  sf::Texture z2Run6Texture;
  sf::Texture z2Fall1Texture;
  sf::Texture z2Fall2Texture;
  sf::Texture z2Fall3Texture;
  sf::Texture z2Dead1Texture;
  sf::Texture z2Dead2Texture;
  sf::Texture z2Dead3Texture;
  sf::Texture z2Dead4Texture;
  sf::Texture z2Dead5Texture;
  sf::Texture z2Dead6Texture;
  sf::Texture z2Dead7Texture;
  sf::Texture z2Dead8Texture;
  sf::Texture z3Run1Texture;
  sf::Texture z3Run2Texture;
  sf::Texture z3Run3Texture;
  sf::Texture z3Run4Texture;
  sf::Texture z3Run5Texture;
  sf::Texture z3Run6Texture;
  sf::Texture z3Fall1Texture;
  sf::Texture z3Fall2Texture;
  sf::Texture z3Fall3Texture;
  sf::Texture z3Dead1Texture;
  sf::Texture z3Dead2Texture;
  sf::Texture z3Dead3Texture;
  sf::Texture z3Dead4Texture;
  sf::Texture z3Dead5Texture;
  sf::Texture z3Dead6Texture;
  sf::Texture z3Dead7Texture;
  sf::Texture z3Dead8Texture;

  void loadZ1Textures();

  void loadZ2Textures();

  void loadZ3Textures();

  void loadZ1RunTextures();

  void loadZ1FallTextures();

  void loadZ1DeadTextures();

  void loadZ2RunTextures();

  void loadZ2FallTextures();

  void loadZ2DeadTextures();

  void loadZ3RunTextures();

  void loadZ3FallTextures();

  void loadZ3DeadTextures();

public:
  std::vector<sf::Texture> zombie1RunTextures;
  std::vector<sf::Texture> zombie1FallTextures;
  std::vector<sf::Texture> zombie1DeadTextures;
  std::vector<sf::Texture> zombie2RunTextures;
  std::vector<sf::Texture> zombie2FallTextures;
  std::vector<sf::Texture> zombie2DeadTextures;
  std::vector<sf::Texture> zombie3RunTextures;
  std::vector<sf::Texture> zombie3FallTextures;
  std::vector<sf::Texture> zombie3DeadTextures;

  void loadTextures();

};


#endif //R_S_ZOMBIE_TEXTURES_H
