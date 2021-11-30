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
  if (zombie.standUpClock.getElapsedTime().asMilliseconds() > 100 && zombie.fallDownTextureCounter < 2) {
    zombie.fallDownTextureCounter++;
    setNewFallTexture(zombie);
    zombie.standUpClock.restart();
  }
}

void ZombieAnimations::deadAnim(Zombie &zombie) {
  if (zombie.deadClock.getElapsedTime().asMilliseconds() > 80 && zombie.deadTextureCounter < 8) {
    setNewDeadTexture(zombie);
    zombie.deadTextureCounter++;
    zombie.deadClock.restart();
  } else if (
      zombie.deadClock.getElapsedTime().asMilliseconds() > 80 &&
      zombie.deadTextureCounter >= 8 &&
      zombie.deadTextureCounter < 18
      ) {
    zombie.deadTextureCounter++;
    if (zombie.deadTextureCounter >= 12) {
      fadeOutAnim(zombie);
    }
    zombie.deadClock.restart();
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
      zombie.setTexture(textures.zombie1FallTextures[zombie.fallDownTextureCounter]);
      break;
    case man2:
      zombie.setTexture(textures.zombie2FallTextures[zombie.fallDownTextureCounter]);
      break;
    case woman:
      zombie.setTexture(textures.zombie3FallTextures[zombie.fallDownTextureCounter]);
      break;
  }
}

void ZombieAnimations::setNewDeadTexture(Zombie &zombie) {
  switch (zombie.type) {
    case man1:
      zombie.setTexture(textures.zombie1DeadTextures[zombie.deadTextureCounter]);
      break;
    case man2:
      zombie.setTexture(textures.zombie2DeadTextures[zombie.deadTextureCounter]);
      break;
    case woman:
      zombie.setTexture(textures.zombie3DeadTextures[zombie.deadTextureCounter]);
      break;
  }
}

void ZombieAnimations::fadeOutAnim(Zombie &zombie) {
  sf::Uint8 alpha = 255 - ((zombie.deadTextureCounter % 12) * 42);
  zombie.sprite.setColor(sf::Color(255, 255, 255, alpha));
}
