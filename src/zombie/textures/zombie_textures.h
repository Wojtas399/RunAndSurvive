#ifndef R_S_ZOMBIE_TEXTURES_H
#define R_S_ZOMBIE_TEXTURES_H

#include <SFML/Graphics.hpp>
#include <iostream>

class ZombieTextures {
private:
  // Zombie 1
  sf::Texture z1Walk1Texture;
  sf::Texture z1Walk2Texture;
  sf::Texture z1Walk3Texture;
  sf::Texture z1Walk4Texture;
  sf::Texture z1Walk5Texture;
  sf::Texture z1Walk6Texture;
  sf::Texture z1Idle1Texture;
  sf::Texture z1Idle2Texture;
  sf::Texture z1Idle3Texture;
  sf::Texture z1Idle4Texture;
  sf::Texture z1Jump1Texture;
  sf::Texture z1Attack1Texture;
  sf::Texture z1Attack2Texture;
  sf::Texture z1Attack3Texture;
  sf::Texture z1Attack4Texture;
  sf::Texture z1Attack5Texture;
  sf::Texture z1Attack6Texture;

  // Zombie 2
  sf::Texture z2Walk1Texture;
  sf::Texture z2Walk2Texture;
  sf::Texture z2Walk3Texture;
  sf::Texture z2Walk4Texture;
  sf::Texture z2Walk5Texture;
  sf::Texture z2Walk6Texture;
  sf::Texture z2Idle1Texture;
  sf::Texture z2Idle2Texture;
  sf::Texture z2Idle3Texture;
  sf::Texture z2Idle4Texture;
  sf::Texture z2Jump1Texture;
  sf::Texture z2Attack1Texture;
  sf::Texture z2Attack2Texture;
  sf::Texture z2Attack3Texture;
  sf::Texture z2Attack4Texture;
  sf::Texture z2Attack5Texture;
  sf::Texture z2Attack6Texture;

  // Zombie 3
  sf::Texture z3Walk1Texture;
  sf::Texture z3Walk2Texture;
  sf::Texture z3Walk3Texture;
  sf::Texture z3Walk4Texture;
  sf::Texture z3Walk5Texture;
  sf::Texture z3Walk6Texture;
  sf::Texture z3Idle1Texture;
  sf::Texture z3Idle2Texture;
  sf::Texture z3Idle3Texture;
  sf::Texture z3Idle4Texture;
  sf::Texture z3Jump1Texture;
  sf::Texture z3Attack1Texture;
  sf::Texture z3Attack2Texture;
  sf::Texture z3Attack3Texture;
  sf::Texture z3Attack4Texture;
  sf::Texture z3Attack5Texture;
  sf::Texture z3Attack6Texture;

  void loadZ1Textures();

  void loadZ2Textures();

  void loadZ3Textures();

  void loadZ1WalkTextures();

  void loadZ1IdleTextures();

  void loadZ1JumpTextures();

  void loadZ1AttackTextures();

  void loadZ2WalkTextures();

  void loadZ2IdleTextures();

  void loadZ2JumpTextures();

  void loadZ2AttackTextures();

  void loadZ3WalkTextures();

  void loadZ3IdleTextures();

  void loadZ3JumpTextures();

  void loadZ3AttackTextures();

public:
  std::vector<sf::Texture> zombie1WalkTextures;
  std::vector<sf::Texture> zombie1IdleTextures;
  std::vector<sf::Texture> zombie1JumpTextures;
  std::vector<sf::Texture> zombie1AttackTextures;
  std::vector<sf::Texture> zombie2WalkTextures;
  std::vector<sf::Texture> zombie2IdleTextures;
  std::vector<sf::Texture> zombie2JumpTextures;
  std::vector<sf::Texture> zombie2AttackTextures;
  std::vector<sf::Texture> zombie3WalkTextures;
  std::vector<sf::Texture> zombie3IdleTextures;
  std::vector<sf::Texture> zombie3JumpTextures;
  std::vector<sf::Texture> zombie3AttackTextures;

  void loadTextures();

};


#endif //R_S_ZOMBIE_TEXTURES_H
