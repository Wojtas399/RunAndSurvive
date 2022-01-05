#include "zombie_textures.h"

void ZombieTextures::loadTextures() {
  loadZ1Textures();
  loadZ2Textures();
  loadZ3Textures();
}

void ZombieTextures::loadZ1Textures() {
  loadZ1RunTextures();
  loadZ1IdleTextures();
  loadZ1JumpTextures();
  loadZ1AttackTextures();
}

void ZombieTextures::loadZ2Textures() {
  loadZ2RunTextures();
  loadZ2IdleTextures();
  loadZ2JumpTextures();
  loadZ2AttackTextures();
}

void ZombieTextures::loadZ3Textures() {
  loadZ3RunTextures();
  loadZ3IdleTextures();
  loadZ3JumpTextures();
  loadZ3AttackTextures();
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

void ZombieTextures::loadZ1IdleTextures() {
  if (
      !z1Idle1Texture.loadFromFile("assets/zombie/zombie1/idle_1.png") ||
      !z1Idle2Texture.loadFromFile("assets/zombie/zombie1/idle_2.png") ||
      !z1Idle3Texture.loadFromFile("assets/zombie/zombie1/idle_3.png") ||
      !z1Idle4Texture.loadFromFile("assets/zombie/zombie1/idle_4.png")
      ) {
    std::cout << "Cannot load one of the zombie 1 idle textures\n";
  }

  zombie1IdleTextures.insert(zombie1IdleTextures.end(), {
      z1Idle1Texture,
      z1Idle2Texture,
      z1Idle3Texture,
      z1Idle4Texture,
  });
}

void ZombieTextures::loadZ1JumpTextures() {
  if (
      !z1Jump1Texture.loadFromFile("assets/zombie/zombie1/jump_1.png") ||
      !z1Jump2Texture.loadFromFile("assets/zombie/zombie1/jump_2.png") ||
      !z1Jump3Texture.loadFromFile("assets/zombie/zombie1/jump_3.png")
      ) {
    std::cout << "Cannot load one of the zombie 1 jump textures\n";
  }

  zombie1JumpTextures.insert(zombie1JumpTextures.end(), {
      z1Jump1Texture,
      z1Jump2Texture,
      z1Jump3Texture,
  });
}

void ZombieTextures::loadZ1AttackTextures() {
  if (
      !z1Attack1Texture.loadFromFile("assets/zombie/zombie1/attack_1.png") ||
      !z1Attack2Texture.loadFromFile("assets/zombie/zombie1/attack_2.png") ||
      !z1Attack3Texture.loadFromFile("assets/zombie/zombie1/attack_3.png") ||
      !z1Attack4Texture.loadFromFile("assets/zombie/zombie1/attack_4.png") ||
      !z1Attack5Texture.loadFromFile("assets/zombie/zombie1/attack_5.png") ||
      !z1Attack6Texture.loadFromFile("assets/zombie/zombie1/attack_6.png")
      ) {
    std::cout << "Cannot load one of the zombie 1 attack textures\n";
  }

  zombie1AttackTextures.insert(zombie1AttackTextures.end(), {
      z1Attack1Texture,
      z1Attack2Texture,
      z1Attack3Texture,
      z1Attack4Texture,
      z1Attack5Texture,
      z1Attack6Texture
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

void ZombieTextures::loadZ2IdleTextures() {
  if (
      !z2Idle1Texture.loadFromFile("assets/zombie/zombie2/idle_1.png") ||
      !z2Idle2Texture.loadFromFile("assets/zombie/zombie2/idle_2.png") ||
      !z2Idle3Texture.loadFromFile("assets/zombie/zombie2/idle_3.png") ||
      !z2Idle4Texture.loadFromFile("assets/zombie/zombie2/idle_4.png")
      ) {
    std::cout << "Cannot load one of the zombie 2 idle textures\n";
  }

  zombie2IdleTextures.insert(zombie2IdleTextures.end(), {
      z2Idle1Texture,
      z2Idle2Texture,
      z2Idle3Texture,
      z2Idle4Texture,
  });
}

void ZombieTextures::loadZ2JumpTextures() {
  if (
      !z2Jump1Texture.loadFromFile("assets/zombie/zombie2/jump_1.png") ||
      !z2Jump2Texture.loadFromFile("assets/zombie/zombie2/jump_2.png") ||
      !z2Jump3Texture.loadFromFile("assets/zombie/zombie2/jump_3.png")
      ) {
    std::cout << "Cannot load one of the zombie 2 jump textures\n";
  }

  zombie2JumpTextures.insert(zombie2JumpTextures.end(), {
      z2Jump1Texture,
      z2Jump2Texture,
      z2Jump3Texture,
  });
}

void ZombieTextures::loadZ2AttackTextures() {
  if (
      !z2Attack1Texture.loadFromFile("assets/zombie/zombie2/attack_1.png") ||
      !z2Attack2Texture.loadFromFile("assets/zombie/zombie2/attack_2.png") ||
      !z2Attack3Texture.loadFromFile("assets/zombie/zombie2/attack_3.png") ||
      !z2Attack4Texture.loadFromFile("assets/zombie/zombie2/attack_4.png") ||
      !z2Attack5Texture.loadFromFile("assets/zombie/zombie2/attack_5.png") ||
      !z2Attack6Texture.loadFromFile("assets/zombie/zombie2/attack_6.png")
      ) {
    std::cout << "Cannot load one of the zombie 2 attack textures\n";
  }

  zombie2AttackTextures.insert(zombie2AttackTextures.end(), {
      z2Attack1Texture,
      z2Attack2Texture,
      z2Attack3Texture,
      z2Attack4Texture,
      z2Attack5Texture,
      z2Attack6Texture
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

void ZombieTextures::loadZ3IdleTextures() {
  if (
      !z3Idle1Texture.loadFromFile("assets/zombie/zombie3/idle_1.png") ||
      !z3Idle2Texture.loadFromFile("assets/zombie/zombie3/idle_2.png") ||
      !z3Idle3Texture.loadFromFile("assets/zombie/zombie3/idle_3.png") ||
      !z3Idle4Texture.loadFromFile("assets/zombie/zombie3/idle_4.png")
      ) {
    std::cout << "Cannot load one of the zombie 3 idle textures\n";
  }

  zombie3IdleTextures.insert(zombie3IdleTextures.end(), {
      z3Idle1Texture,
      z3Idle2Texture,
      z3Idle3Texture,
      z3Idle4Texture,
  });
}

void ZombieTextures::loadZ3JumpTextures() {
  if (
      !z3Jump1Texture.loadFromFile("assets/zombie/zombie3/jump_1.png") ||
      !z3Jump2Texture.loadFromFile("assets/zombie/zombie3/jump_2.png") ||
      !z3Jump3Texture.loadFromFile("assets/zombie/zombie3/jump_3.png")
      ) {
    std::cout << "Cannot load one of the zombie 3 jump textures\n";
  }

  zombie3JumpTextures.insert(zombie3JumpTextures.end(), {
      z3Jump1Texture,
      z3Jump2Texture,
      z3Jump3Texture,
  });
}

void ZombieTextures::loadZ3AttackTextures() {
  if (
      !z3Attack1Texture.loadFromFile("assets/zombie/zombie3/attack_1.png") ||
      !z3Attack2Texture.loadFromFile("assets/zombie/zombie3/attack_2.png") ||
      !z3Attack3Texture.loadFromFile("assets/zombie/zombie3/attack_3.png") ||
      !z3Attack4Texture.loadFromFile("assets/zombie/zombie3/attack_4.png") ||
      !z3Attack5Texture.loadFromFile("assets/zombie/zombie3/attack_5.png") ||
      !z3Attack6Texture.loadFromFile("assets/zombie/zombie3/attack_6.png")
      ) {
    std::cout << "Cannot load one of the zombie 3 attack textures\n";
  }

  zombie3AttackTextures.insert(zombie3AttackTextures.end(), {
      z3Attack1Texture,
      z3Attack2Texture,
      z3Attack3Texture,
      z3Attack4Texture,
      z3Attack5Texture,
      z3Attack6Texture
  });
}
