#include "robot_shoot_controller.h"

void RobotShootController::draw(sf::RenderWindow &window) {
  for (Bullet &bullet: allBullets) {
    window.draw(bullet.muzzleCounter >= 0 ? bullet.muzzleSprite : bullet.bulletSprite);
  }
}

void RobotShootController::move() {
  for (int i = 0; i < allBullets.size(); i++) {
    movementController(allBullets[i], i);
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

void RobotShootController::movementController(Bullet &bullet, int bulletIndex) {
  sf::Vector2<float> bulletPosition = bullet.getBulletPosition();
  if (isCollisionWithMapElement(bullet)) {
    bullet.isExplosion = true;
  }
  if (
      bulletPosition.x > 1400 ||
      bulletPosition.x < 0 ||
      bullet.muzzleCounter >= 5
      ) {
    allBullets.erase(allBullets.begin() + bulletIndex);
  } else {
    setNewBulletParams(bullet, bulletIndex);
  }
}

void RobotShootController::setNewBulletParams(Bullet &bullet, int bulletIndex) {
  sf::Vector2<float> bulletScale = bullet.bulletSprite.getScale();
  float expectedScale = constants::bulletScale;
  if (bullet.isExplosion && bullet.muzzleCounter > -1) {
    muzzleAnim(bullet, bulletIndex);
  } else if (bullet.isExplosion && bullet.muzzleCounter == -1) {
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
  setNewBulletPosition(bullet);
}

void RobotShootController::setNewBulletPosition(Bullet &bullet) {
  sf::Vector2<float> bulletPosition = bullet.getBulletPosition();
  sf::Vector2<float> muzzlePosition = bullet.getMuzzlePosition();
  float x = bulletPosition.x;
  float y = bulletPosition.y;
  if (bullet.muzzleCounter == -1) {
    bullet.setBulletPosition(x + bullet.speed, y);
  } else {
    bullet.setMuzzlePosition(
        bullet.muzzleCounter == 0 && isCollisionWithMapElement(bullet)
        ? x + (bullet.isReversed ? -26.0f : 10.0f)
        : muzzlePosition.x - constants::mapSpeed,
        y
    );
  }
}

void RobotShootController::muzzleAnim(Bullet &bullet, int &bulletIndex) {
  if (bullet.muzzleCounter < 5 && bullet.textureClock.getElapsedTime().asMilliseconds() > 40) {
    bullet.muzzleSprite.setTexture(robotTextures.muzzlesTextures[bullet.muzzleCounter]);
    bullet.textureClock.restart();
    bullet.muzzleCounter++;
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
      bullet.isReversed ? scale.x - 0.02f : scale.x + 0.02f,
      scale.y + 0.02f
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

bool RobotShootController::isCollisionWithMapElement(Bullet &bullet) {
  return bulletCollisions.isCollisionWithGroundElement(bullet) ||
         bulletCollisions.isCollisionWithAirElement(bullet);
}
