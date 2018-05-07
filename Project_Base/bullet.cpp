#include "bullet.h"

void bullet::bulletMov (float yVel, float speed, float xPos, float yPos, bool fFire) {

    this->yVel = yVel;
    this->speed = speed;
    this->xPos = xPos;
    this->yPos = yPos;
    this->fFire = fFire;
}

void bullet::drawBullet(){}

