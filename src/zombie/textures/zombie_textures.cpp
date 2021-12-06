#include "zombie_textures.h"

void ZombieTextures::loadTextures() {
  loadZ1Textures();
  loadZ2Textures();
  loadZ3Textures();
}

void ZombieTextures::loadZ1Textures() {
  loadZ1RunTextures();
  loadZ1FallTextures();
}

void ZombieTextures::loadZ2Textures() {
  loadZ2RunTextures();
  loadZ2FallTextures();
}

void ZombieTextures::loadZ3Textures() {
  loadZ3RunTextures();
  loadZ3FallTextures();
}

void ZombieTextures::loadZ1RunTextures() {
  if (
      !z1Run1Texture.loadFromFile("assets/zombie/zombie1/walk_1.png") ||
      !z1Run2Texture.loadFromFile("assets/zombie/zombie1/walk_2.png") ||
      !z1Run3Texture.loadFromFile("assets/zombie/zombie1/walk_3.png") ||
      !z1Run4Texture.loadFromFile("assets/zombie/zombie1/walk_4.png") ||
      !z1Run5Texture.loadFromFile("assets/zombie/zombie1/walk_5.png") ||
      !z1Run6Texture.loadFromFile("assets/zombie/zombie1/walk_6.png")
      ) {
    std::cout << "Cannot load one of the zombie 1 run textures\n";
  }

  zombie1RunTextures.insert(zombie1RunTextures.end(), {
      z1Run1Texture,
      z1Run2Texture,
      z1Run3Texture,
      z1Run4Texture,
      z1Run5Texture,
      z1Run6Texture,
  });
}

void ZombieTextures::loadZ1FallTextures() {
  if (
      !z1Fall1Texture.loadFromFile("assets/zombie/zombie1/fall_1.png") ||
      !z1Fall2Texture.loadFromFile("assets/zombie/zombie1/fall_2.png") ||
      !z1Fall3Texture.loadFromFile("assets/zombie/zombie1/fall_3.png")
      ) {
    std::cout << "Cannot load one of the zombie 1 fall textures\n";
  }

  zombie1FallTextures.insert(zombie1FallTextures.end(), {
      z1Fall1Texture,
      z1Fall2Texture,
      z1Fall3Texture,
  });
}

void ZombieTextures::loadZ2RunTextures() {
  if (
      !z2Run1Texture.loadFromFile("assets/zombie/zombie2/walk_1.png") ||
      !z2Run2Texture.loadFromFile("assets/zombie/zombie2/walk_2.png") ||
      !z2Run3Texture.loadFromFile("assets/zombie/zombie2/walk_3.png") ||
      !z2Run4Texture.loadFromFile("assets/zombie/zombie2/walk_4.png") ||
      !z2Run5Texture.loadFromFile("assets/zombie/zombie2/walk_5.png") ||
      !z2Run6Texture.loadFromFile("assets/zombie/zombie2/walk_6.png")
      ) {
    std::cout << "Cannot load one of the zombie 2 run textures\n";
  }

  zombie2RunTextures.insert(zombie2RunTextures.end(), {
      z2Run1Texture,
      z2Run2Texture,
      z2Run3Texture,
      z2Run4Texture,
      z2Run5Texture,
      z2Run6Texture,
  });
}

void ZombieTextures::loadZ2FallTextures() {
  if (
      !z2Fall1Texture.loadFromFile("assets/zombie/zombie2/fall_1.png") ||
      !z2Fall2Texture.loadFromFile("assets/zombie/zombie2/fall_2.png") ||
      !z2Fall3Texture.loadFromFile("assets/zombie/zombie2/fall_3.png")
      ) {
    std::cout << "Cannot load one of the zombie 2 fall textures\n";
  }

  zombie2FallTextures.insert(zombie2FallTextures.end(), {
      z2Fall1Texture,
      z2Fall2Texture,
      z2Fall3Texture,
  });
}

void ZombieTextures::loadZ3RunTextures() {
  if (
      !z3Run1Texture.loadFromFile("assets/zombie/zombie3/walk_1.png") ||
      !z3Run2Texture.loadFromFile("assets/zombie/zombie3/walk_2.png") ||
      !z3Run3Texture.loadFromFile("assets/zombie/zombie3/walk_3.png") ||
      !z3Run4Texture.loadFromFile("assets/zombie/zombie3/walk_4.png") ||
      !z3Run5Texture.loadFromFile("assets/zombie/zombie3/walk_5.png") ||
      !z3Run6Texture.loadFromFile("assets/zombie/zombie3/walk_6.png")
      ) {
    std::cout << "Cannot load one of the zombie 3 run textures\n";
  }

  zombie3RunTextures.insert(zombie3RunTextures.end(), {
      z3Run1Texture,
      z3Run2Texture,
      z3Run3Texture,
      z3Run4Texture,
      z3Run5Texture,
      z3Run6Texture,
  });
}

void ZombieTextures::loadZ3FallTextures() {
  if (
      !z3Fall1Texture.loadFromFile("assets/zombie/zombie3/fall_1.png") ||
      !z3Fall2Texture.loadFromFile("assets/zombie/zombie3/fall_2.png") ||
      !z3Fall3Texture.loadFromFile("assets/zombie/zombie3/fall_3.png")
      ) {
    std::cout << "Cannot load one of the zombie 3 fall textures\n";
  }

  zombie3FallTextures.insert(zombie3FallTextures.end(), {
      z3Fall1Texture,
      z3Fall2Texture,
      z3Fall3Texture,
  });
}
