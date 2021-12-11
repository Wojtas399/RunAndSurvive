#include "zombie_animations.h"

void ZombieAnimations::loadTextures() {
  textures.loadTextures();
}

void ZombieAnimations::runAnim(Zombie &zombie) {
  if (zombie.clock.getElapsedTime().asMilliseconds() > 125) {
    setNewRunTexture(zombie);
    zombie.runTextureCounter++;
    if (zombie.runTextureCounter >= 6) {
      zombie.runTextureCounter = 0;
    }
    zombie.clock.restart();
  }
}

void ZombieAnimations::fallAnim(Zombie &zombie) {
  setNewFallTexture(zombie);
}

void ZombieAnimations::standUpAnim(Zombie &zombie) {
  if (zombie.standUpClock.getElapsedTime().asMilliseconds() > 100 && zombie.fallDownTextureCounter < 2) {
    zombie.fallDownTextureCounter++;
    setNewFallTexture(zombie);
    zombie.standUpClock.restart();
  }
}

void ZombieAnimations::attackAnim(Zombie &zombie) {
  if (zombie.clock.getElapsedTime().asMilliseconds() > 80 && zombie.attackTextureCounter < 6) {
    setNewAttackTexture(zombie);
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
