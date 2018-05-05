//bulletMov.cpp

#include "bulletMov.h"

class bulletMov {

  float xVel; //Velocity of bullet in X-Direction
  float yVel; //Velocity of bullet in Y-Direction
  float speed; //set speed of bullet in direction it's going
  float xPos; //position of bullet in the X-Direction
  float yPos; //position of bullet in the Y-Direction
  bool friendlyFire; //determine if bullet is from MC or Enemy
  bool contact; //Check if the bullet has come in contact with the enemy/MC (based on the value of friendlyFire)

  //Speed will represent distance it will travel in one second (1000 milliseconds)
  //friendlyFire will determine if bullet will interact with MC or Enemy
public:

  bulletMov(float x, float y, float s, float xp, float yp, bool fFire) {
    xVel = x;
    yVel = y;
    speed = s;
    xPos = xp;
    yPos = yp;
    friendlyFire = fFire;
  }

  void updatePos() {
    xPos += xVel;
    yPos += yVel;
  }

  void initiateContact() {
    contact = true;
  }
}
