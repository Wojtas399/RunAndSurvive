#include "zombie_animations.h"

void ZombieAnimations::loadTextures() {
  textures.loadTextures();
}

void ZombieAnimations::runAnim(Zombie &zombie) {
  if (zombie.textureClock.getElapsedTime().asMilliseconds() > 125) {
    setNewRunTexture(zombie);
    zombie.runTextureCounter++;
    if (zombie.runTextureCounter >= 6) {
      zombie.runTextureCounter = 0;
    }
    zombie.textureClock.restart();
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
