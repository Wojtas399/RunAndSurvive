#include "robot_shoot_controller.h"

void RobotShootController::draw(sf::RenderWindow &window) {
  for (Bullet &bullet: allBullets) {
    window.draw(bullet.sprite);
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
  newBullet.speed = robot.isReversed ? -0.1f : 0.06f;
  newBullet.sprite.setTexture(robotTextures.bulletsTextures[0]);
  newBullet.sprite.setOrigin(0, 60);
  newBullet.sprite.setScale(0.0, 0.0);
  newBullet.setPosition(robot.isReversed ? robotPosition.x - 64 : robotPosition.x + 64, robotPosition.y + 44);
  allBullets.push_back(newBullet);
}

void RobotShootController::setNewBulletParams(Bullet &bullet, int bulletIndex) {
  sf::Vector2<float> bulletPosition = bullet.getPosition();
  sf::Vector2<float> bulletScale = bullet.sprite.getScale();
  float x = bulletPosition.x + bullet.speed;
  float y = bulletPosition.y;
  if (
      ((bullet.isReversed && bulletScale.x > -0.20) || (!bullet.isReversed && bulletScale.x < 0.20)) &&
      bulletScale.y < 0.20 &&
      bullet.textureClock.getElapsedTime().asMilliseconds() > 2
      ) {
    bullet.sprite.setScale(
        bullet.isReversed ? bulletScale.x - 0.01f : bulletScale.x + 0.01f,
        bulletScale.y + 0.01f
    );
    bullet.textureClock.restart();
  } else if (bullet.textureClock.getElapsedTime().asMilliseconds() > 30) {
    bullet.textureCounter++;
    if (bullet.textureCounter > 4) {
      bullet.textureCounter = 0;
    }
    bullet.sprite.setTexture(robotTextures.bulletsTextures[bullet.textureCounter]);
    bullet.textureClock.restart();
  }
  if (x > 1400 || x < 0) {
    allBullets.erase(allBullets.begin() + bulletIndex);
  } else {
    bullet.setPosition(x, y);
  }
}
