#include "robot_shoot_controller.h"

void RobotShootController::draw(sf::RenderWindow &window) {
  for (Bullet &bullet: allBullets) {
    window.draw(bullet.muzzleCounter >= 0 ? bullet.muzzleSprite : bullet.bulletSprite);
  }
}

void RobotShootController::move() {
  for (int i = 0; i < allBullets.size(); i++) {
    setNewBulletParams(allBullets[i], i);
  }
}

void RobotShootController::shoot() {
  sf::Vector2<float> robotPosition = robot.getPosition();
  Bullet newBullet;
  newBullet.isReversed = robot.isReversed;
  newBullet.speed = robot.isReversed ? -0.12f : 0.06f;
  newBullet.bulletSprite.setTexture(robotTextures.bulletsTextures[0]);
  newBullet.bulletSprite.setOrigin(0, 60);
  newBullet.bulletSprite.setScale(0.0, 0.0);
  newBullet.setBulletPosition(robot.isReversed ? robotPosition.x - 64 : robotPosition.x + 64, robotPosition.y + 44);
  allBullets.push_back(newBullet);
  std::cout << "Bullets amount on the map: " << allBullets.size() << "\n";
}

void RobotShootController::setNewBulletParams(Bullet &bullet, int bulletIndex) {
  sf::Vector2<float> bulletPosition = bullet.getBulletPosition();
  sf::Vector2<float> muzzlePosition = bullet.getMuzzlePosition();
  sf::Vector2<float> bulletScale = bullet.bulletSprite.getScale();
  float x = bulletPosition.x;
  float y = bulletPosition.y;
  float expectedScale = constants::bulletScale;
  bool isDeleted = false;
  if (bullet.muzzleCounter > -1) {
    muzzleAnim(bullet, bulletIndex, isDeleted);
  } else if (
      (
          bulletCollisions.isCollisionWithGroundElement(bullet) ||
          bulletCollisions.isCollisionWithAirElement(bullet)
      ) && bullet.muzzleCounter == -1
      ) {
    startMuzzleAnim(bullet);
  } else if (
      (
          (bullet.isReversed && bulletScale.x > -expectedScale) ||
          (!bullet.isReversed && bulletScale.x < expectedScale)
      ) &&
      bulletScale.y < expectedScale &&
      bullet.textureClock.getElapsedTime().asMilliseconds() > 2
      ) {
    setBulletOrientation(bullet, bulletScale);
  } else if (bullet.textureClock.getElapsedTime().asMilliseconds() > 25) {
    setNextBulletTexture(bullet);
  }
  if (
      x > 1400 ||
      x < 0
      ) {
    allBullets.erase(allBullets.begin() + bulletIndex);
    isDeleted = true;
  }
  if (!isDeleted) {
    if (bullet.muzzleCounter == -1) {
      bullet.setBulletPosition(x + bullet.speed, y);
    } else {
      bullet.setMuzzlePosition(
          bullet.muzzleCounter == 0
          ? x + (bullet.isReversed ? -26.0f : 10.0f)
          : muzzlePosition.x - constants::mapSpeed,
          y
      );
    }
  }
}

void RobotShootController::muzzleAnim(Bullet &bullet, int &bulletIndex, bool &isDeleted) {
  if (bullet.muzzleCounter < 5 && bullet.textureClock.getElapsedTime().asMilliseconds() > 30) {
    bullet.muzzleSprite.setTexture(robotTextures.muzzlesTextures[bullet.muzzleCounter]);
    bullet.textureClock.restart();
    bullet.muzzleCounter++;
  } else if (bullet.muzzleCounter == 5) {
    allBullets.erase(allBullets.begin() + bulletIndex);
    isDeleted = true;
  }
}

void RobotShootController::startMuzzleAnim(Bullet &bullet) {
  bullet.muzzleCounter = 0;
  bullet.muzzleSprite.setScale(1.5, 0.5);
  bullet.muzzleSprite.setOrigin(9, 108);
  bullet.textureClock.restart();
}

void RobotShootController::setBulletOrientation(Bullet &bullet, sf::Vector2<float> scale) {
  bullet.bulletSprite.setScale(
      bullet.isReversed ? scale.x - 0.01f : scale.x + 0.01f,
      scale.y + 0.01f
  );
  bullet.textureClock.restart();
}

void RobotShootController::setNextBulletTexture(Bullet &bullet) {
  bullet.bulletCounter++;
  if (bullet.bulletCounter > 4) {
    bullet.bulletCounter = 0;
  }
  bullet.bulletSprite.setTexture(robotTextures.bulletsTextures[bullet.bulletCounter]);
  bullet.textureClock.restart();
}
