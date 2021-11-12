#include "robot_textures.h"

void RobotTextures::load() {
  loadRunTextures();
  loadJumpTextures();
  loadIdleTextures();
  loadSlideTextures();
  loadShootTextures();
  loadBulletsTextures();
}

void RobotTextures::loadRunTextures() {
  if (
      !run1Texture.loadFromFile("assets/robot/run_1.png") ||
      !run2Texture.loadFromFile("assets/robot/run_2.png") ||
      !run3Texture.loadFromFile("assets/robot/run_3.png") ||
      !run4Texture.loadFromFile("assets/robot/run_4.png") ||
      !run5Texture.loadFromFile("assets/robot/run_5.png") ||
      !run6Texture.loadFromFile("assets/robot/run_6.png") ||
      !run7Texture.loadFromFile("assets/robot/run_7.png") ||
      !run8Texture.loadFromFile("assets/robot/run_8.png")
      ) {
    std::cout << "Cannot load one of the run textures";
  }
  runTextures.insert(runTextures.end(), {
      run1Texture,
      run2Texture,
      run3Texture,
      run4Texture,
      run5Texture,
      run6Texture,
      run7Texture,
      run8Texture,
  });
}

void RobotTextures::loadJumpTextures() {
  if (
      !jump1Texture.loadFromFile("assets/robot/jump_1.png") ||
      !jump2Texture.loadFromFile("assets/robot/jump_2.png") ||
      !jump3Texture.loadFromFile("assets/robot/jump_3.png") ||
      !jump4Texture.loadFromFile("assets/robot/jump_4.png") ||
      !jump5Texture.loadFromFile("assets/robot/jump_5.png") ||
      !jump6Texture.loadFromFile("assets/robot/jump_6.png") ||
      !jump7Texture.loadFromFile("assets/robot/jump_7.png") ||
      !jump8Texture.loadFromFile("assets/robot/jump_8.png") ||
      !jump9Texture.loadFromFile("assets/robot/jump_9.png") ||
      !jump10Texture.loadFromFile("assets/robot/jump_10.png")
      ) {
    std::cout << "Cannot load one of the jump textures";
  }
  jumpTextures.insert(jumpTextures.end(), {
      jump1Texture,
      jump2Texture,
      jump3Texture,
      jump4Texture,
      jump5Texture,
      jump6Texture,
      jump7Texture,
      jump8Texture,
      jump9Texture,
      jump10Texture
  });
}

void RobotTextures::loadIdleTextures() {
  if (
      !idle1Texture.loadFromFile("assets/robot/idle_1.png") ||
      !idle2Texture.loadFromFile("assets/robot/idle_2.png") ||
      !idle3Texture.loadFromFile("assets/robot/idle_3.png") ||
      !idle4Texture.loadFromFile("assets/robot/idle_4.png") ||
      !idle5Texture.loadFromFile("assets/robot/idle_5.png") ||
      !idle6Texture.loadFromFile("assets/robot/idle_6.png") ||
      !idle7Texture.loadFromFile("assets/robot/idle_7.png") ||
      !idle8Texture.loadFromFile("assets/robot/idle_8.png") ||
      !idle9Texture.loadFromFile("assets/robot/idle_9.png") ||
      !idle10Texture.loadFromFile("assets/robot/idle_10.png")
      ) {
    std::cout << "Cannot load one of the idle textures";
  }
  idleTextures.insert(idleTextures.end(), {
      idle1Texture,
      idle2Texture,
      idle3Texture,
      idle4Texture,
      idle5Texture,
      idle6Texture,
      idle7Texture,
      idle8Texture,
      idle9Texture,
      idle10Texture
  });
}

void RobotTextures::loadSlideTextures() {
  if (
      !slide1Texture.loadFromFile("assets/robot/slide_1.png") ||
      !slide2Texture.loadFromFile("assets/robot/slide_2.png") ||
      !slide3Texture.loadFromFile("assets/robot/slide_3.png") ||
      !slide4Texture.loadFromFile("assets/robot/slide_4.png") ||
      !slide5Texture.loadFromFile("assets/robot/slide_5.png") ||
      !slide6Texture.loadFromFile("assets/robot/slide_6.png") ||
      !slide7Texture.loadFromFile("assets/robot/slide_7.png") ||
      !slide8Texture.loadFromFile("assets/robot/slide_8.png") ||
      !slide9Texture.loadFromFile("assets/robot/slide_9.png") ||
      !slide10Texture.loadFromFile("assets/robot/slide_10.png")
      ) {
    std::cout << "Cannot load one of the slide textures";
  }
  slideTextures.insert(slideTextures.end(), {
      slide1Texture,
      slide2Texture,
      slide3Texture,
      slide4Texture,
      slide5Texture,
      slide6Texture,
      slide7Texture,
      slide8Texture,
      slide9Texture,
      slide10Texture
  });
}

void RobotTextures::loadShootTextures() {
  if (
      !shoot1Texture.loadFromFile("assets/robot/run_shoot_1.png") ||
      !shoot2Texture.loadFromFile("assets/robot/run_shoot_2.png") ||
      !shoot3Texture.loadFromFile("assets/robot/run_shoot_3.png") ||
      !shoot4Texture.loadFromFile("assets/robot/run_shoot_4.png") ||
      !shoot5Texture.loadFromFile("assets/robot/run_shoot_5.png") ||
      !shoot6Texture.loadFromFile("assets/robot/run_shoot_6.png") ||
      !shoot7Texture.loadFromFile("assets/robot/run_shoot_7.png") ||
      !shoot8Texture.loadFromFile("assets/robot/run_shoot_8.png") ||
      !shoot9Texture.loadFromFile("assets/robot/run_shoot_9.png")
      ) {
    std::cout << "Cannot load one of the shoot textures";
  }
  shootTextures.insert(shootTextures.end(), {
      shoot1Texture,
      shoot2Texture,
      shoot3Texture,
      shoot4Texture,
      shoot5Texture,
      shoot6Texture,
      shoot7Texture,
      shoot8Texture,
      shoot9Texture
  });
}

void RobotTextures::loadBulletsTextures() {
  if (
      !bullet1Texture.loadFromFile("assets/robot/bullets/bullet_1.png") ||
      !bullet2Texture.loadFromFile("assets/robot/bullets/bullet_2.png") ||
      !bullet3Texture.loadFromFile("assets/robot/bullets/bullet_3.png") ||
      !bullet4Texture.loadFromFile("assets/robot/bullets/bullet_4.png") ||
      !bullet5Texture.loadFromFile("assets/robot/bullets/bullet_5.png")
      ) {
    std::cout << "Cannot load one of the bullet textures";
  }
  bulletsTextures.insert(bulletsTextures.end(), {
      bullet1Texture,
      bullet2Texture,
      bullet3Texture,
      bullet4Texture,
      bullet5Texture
  });
}
