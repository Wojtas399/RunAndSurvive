#include "zombie_animations.h"

void ZombieAnimations::loadTextures() {
  textures.loadTextures();
}

void ZombieAnimations::runAnim(Zombie &zombie) {
  if (zombie.clock.getElapsedTime().asMilliseconds() > 100) {
    setNewRunTexture(zombie);
    zombie.runTextureCounter++;
    if (zombie.runTextureCounter >= 6) {
      zombie.runTextureCounter = 0;
    }
    zombie.clock.restart();
  }
}

void ZombieAnimations::idleAnim(Zombie &zombie) {
  if (zombie.clock.getElapsedTime().asMilliseconds() > 100) {
    setNewIdleTexture(zombie);
    zombie.idleTextureCounter++;
    if (zombie.idleTextureCounter >= 4) {
      zombie.idleTextureCounter = 0;
    }
    zombie.clock.restart();
  }
}

void ZombieAnimations::fallAnim(Zombie &zombie) {
  setNewFallTexture(zombie);
}

void ZombieAnimations::attackAnim(Zombie &zombie) {
  if (zombie.clock.getElapsedTime().asMilliseconds() > 80 && zombie.attackTextureCounter < 6) {
    setNewAttackTexture(zombie);
    if (zombie.attackTextureCounter == 2) {
      lifeService.subtractLife();
    }
    zombie.attackTextureCounter++;
    zombie.clock.restart();
  }
}

void ZombieAnimations::deadAnim(Zombie &zombie) {
  if (zombie.clock.getElapsedTime().asMilliseconds() > 100 && zombie.deadTextureCounter < 8) {
    fadeOutAnim(zombie);
    zombie.deadTextureCounter++;
    zombie.clock.restart();
  }
}

void ZombieAnimations::setNewRunTexture(Zombie &zombie) {
  switch (zombie.type) {
    case man1:
      zombie.setTexture(textures.zombie1RunTextures[zombie.runTextureCounter]);
      break;
    case man2:
      zombie.setTexture(textures.zombie2RunTextures[zombie.runTextureCounter]);
      break;
    case woman:
      zombie.setTexture(textures.zombie3RunTextures[zombie.runTextureCounter]);
      break;
  }
}

void ZombieAnimations::setNewIdleTexture(Zombie &zombie) {
  switch (zombie.type) {
    case man1:
      zombie.setTexture(textures.zombie1IdleTextures[zombie.idleTextureCounter]);
      break;
    case man2:
      zombie.setTexture(textures.zombie2IdleTextures[zombie.idleTextureCounter]);
      break;
    case woman:
      zombie.setTexture(textures.zombie3IdleTextures[zombie.idleTextureCounter]);
      break;
  }
}

void ZombieAnimations::setNewFallTexture(Zombie &zombie) {
  switch (zombie.type) {
    case man1:
      zombie.setTexture(textures.zombie1JumpTextures[zombie.fallDownTextureCounter]);
      break;
    case man2:
      zombie.setTexture(textures.zombie2JumpTextures[zombie.fallDownTextureCounter]);
      break;
    case woman:
      zombie.setTexture(textures.zombie3JumpTextures[zombie.fallDownTextureCounter]);
      break;
  }
}

void ZombieAnimations::setNewAttackTexture(Zombie &zombie) {
  switch (zombie.type) {
    case man1:
      zombie.setTexture(textures.zombie1AttackTextures[zombie.attackTextureCounter]);
      break;
    case man2:
      zombie.setTexture(textures.zombie2AttackTextures[zombie.attackTextureCounter]);
      break;
    case woman:
      zombie.setTexture(textures.zombie3AttackTextures[zombie.attackTextureCounter]);
      break;
  }
}

void ZombieAnimations::fadeOutAnim(Zombie &zombie) {
  sf::Uint8 alpha = 255 - ((zombie.deadTextureCounter % 8) * 31);
  zombie.sprite.setColor(sf::Color(255, 255, 255, alpha));
}
