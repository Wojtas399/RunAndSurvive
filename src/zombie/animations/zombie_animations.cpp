#include "zombie_animations.h"

void ZombieAnimations::loadTextures() {
  textures.loadTextures();
}

void ZombieAnimations::runAnim(Zombie &zombie) {
  if (zombie.runClock.getElapsedTime().asMilliseconds() > 125) {
    setNewRunTexture(zombie);
    zombie.runTextureCounter++;
    if (zombie.runTextureCounter >= 6) {
      zombie.runTextureCounter = 0;
    }
    zombie.runClock.restart();
  }
}

void ZombieAnimations::fallAnim(Zombie &zombie) {
  setNewFallTexture(zombie);
}

void ZombieAnimations::standUpAnim(Zombie &zombie) {
  if (zombie.standUpClock.getElapsedTime().asMilliseconds() > 100) {
    zombie.descentTextureCounter++;
    if (zombie.descentTextureCounter > 2) {
      zombie.isAfterFallingDown = false;
      zombie.descentTextureCounter = 0;
    } else {
      setNewFallTexture(zombie);
    }
    zombie.standUpClock.restart();
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
      zombie.setTexture(textures.zombie1FallTextures[zombie.descentTextureCounter]);
      break;
    case man2:
      zombie.setTexture(textures.zombie2FallTextures[zombie.descentTextureCounter]);
      break;
    case woman:
      zombie.setTexture(textures.zombie3FallTextures[zombie.descentTextureCounter]);
      break;
  }
}
