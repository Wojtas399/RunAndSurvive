#ifndef R_S_ZOMBIE_TEXTURES_H
#define R_S_ZOMBIE_TEXTURES_H

#include <SFML/Graphics.hpp>
#include <iostream>

class ZombieTextures {
private:
  // Zombie 1
  sf::Texture z1Run1Texture;
  sf::Texture z1Run2Texture;
  sf::Texture z1Run3Texture;
  sf::Texture z1Run4Texture;
  sf::Texture z1Run5Texture;
  sf::Texture z1Run6Texture;
  sf::Texture z1Jump1Texture;
  sf::Texture z1Jump2Texture;
  sf::Texture z1Jump3Texture;
  sf::Texture z1Attack1Texture;
  sf::Texture z1Attack2Texture;
  sf::Texture z1Attack3Texture;
  sf::Texture z1Attack4Texture;
  sf::Texture z1Attack5Texture;
  sf::Texture z1Attack6Texture;

  // Zombie 2
  sf::Texture z2Run1Texture;
  sf::Texture z2Run2Texture;
  sf::Texture z2Run3Texture;
  sf::Texture z2Run4Texture;
  sf::Texture z2Run5Texture;
  sf::Texture z2Run6Texture;
  sf::Texture z2Jump1Texture;
  sf::Texture z2Jump2Texture;
  sf::Texture z2Jump3Texture;
  sf::Texture z2Attack1Texture;
  sf::Texture z2Attack2Texture;
  sf::Texture z2Attack3Texture;
  sf::Texture z2Attack4Texture;
  sf::Texture z2Attack5Texture;
  sf::Texture z2Attack6Texture;

  // Zombie 3
  sf::Texture z3Run1Texture;
  sf::Texture z3Run2Texture;
  sf::Texture z3Run3Texture;
  sf::Texture z3Run4Texture;
  sf::Texture z3Run5Texture;
  sf::Texture z3Run6Texture;
  sf::Texture z3Jump1Texture;
  sf::Texture z3Jump2Texture;
  sf::Texture z3Jump3Texture;
  sf::Texture z3Attack1Texture;
  sf::Texture z3Attack2Texture;
  sf::Texture z3Attack3Texture;
  sf::Texture z3Attack4Texture;
  sf::Texture z3Attack5Texture;
  sf::Texture z3Attack6Texture;

  void loadZ1Textures();

  void loadZ2Textures();

  void loadZ3Textures();

  void loadZ1RunTextures();

  void loadZ1JumpTextures();

  void loadZ1AttackTextures();

  void loadZ2RunTextures();

  void loadZ2JumpTextures();

  void loadZ2AttackTextures();

  void loadZ3RunTextures();

  void loadZ3JumpTextures();

  void loadZ3AttackTextures();

public:
  std::vector<sf::Texture> zombie1RunTextures;
  std::vector<sf::Texture> zombie1JumpTextures;
  std::vector<sf::Texture> zombie1AttackTextures;
  std::vector<sf::Texture> zombie2RunTextures;
  std::vector<sf::Texture> zombie2JumpTextures;
  std::vector<sf::Texture> zombie2AttackTextures;
  std::vector<sf::Texture> zombie3RunTextures;
  std::vector<sf::Texture> zombie3JumpTextures;
  std::vector<sf::Texture> zombie3AttackTextures;

  void loadTextures();

};


#endif //R_S_ZOMBIE_TEXTURES_H
