/*
Project Group: Chris Groce, Kevin McGinn, Nick Taylor
CSE 20212
3/25/2012

Enemy.cpp

This is the implementation for the Enemy abstract base class

*/
#include <iostream>
#include "Enemy.h"

Enemy::Enemy(int startX, int startY) {

  xPos = startX;                                // initial positioin of enemy, stored as x and y
  yPos = startY;
  xPrev = startX;
  yPrev = startY;

  health = 10; //default values, can be changed by child classes
  maxHealth = 10;
  speed = 20;
}

int Enemy::getPosX() {                          // returns x position of enemy
  return xPos;
}

int Enemy::getPosY() {                          // returns y position of enemy
  return yPos;
}

int Enemy::isDead(){                            // returns 1 if enemy is dead
  return(health<=0);
}

int Enemy::getSpeed() {                         // returns speed of enemy
  return speed;
}

void Enemy::initHealth(int startHealth) {
    health = startHealth;
    maxHealth = startHealth;
}

void Enemy::initSpeed(int startSpeed) {
    speed = startSpeed;
}

int Enemy::getHealth() {                        // returns health of enemy
  return health;
}

int Enemy::getMaxHealth() {                     // returns the maximum health
  return maxHealth;
}

void Enemy::loseHealth(int damageTaken) {       // depletes health of enemy
  health -= damageTaken;
}

char Enemy::nextSpace(vector<vector<char> > map) {         // determines the next space for the ememy without moving it
    if(map[yPos+1][xPos] == 'P' && yPos+1 != yPrev) {
        return 'd';                                   // next position is down
    }
    else if(map[yPos-1][xPos] == 'P' && yPos-1 != yPrev) {
        return 'u';                                   // next position is up
    }
    else if(map[yPos][xPos+1] == 'P' && xPos+1 != xPrev) {
        return 'r';                                   // next position is right
    }
    else if(map[yPos][xPos-1] == 'P' && xPos-1 != xPrev) {
        return 'l';                                   // next position is left
    }

}



void Enemy::move(vector<vector<char> > map) {           // moves enemy one space forward along the path
  if(map[yPos+1][xPos] == 'P' && yPos+1 != yPrev) {
      yPrev = yPos++;                                   // next position is down
      xPrev = xPos;
  }
  else if(map[yPos-1][xPos] == 'P' && yPos-1 != yPrev) {
      yPrev = yPos--;                                   // next position is up
      xPrev = xPos;
  }
  else if(map[yPos][xPos+1] == 'P' && xPos+1 != xPrev) {
      xPrev = xPos++;                                   // next position is right
      yPrev = yPos;
  }
  else if(map[yPos][xPos-1] == 'P' && xPos-1 != xPrev) {
      xPrev = xPos--;                                   // next position is left
      yPrev = yPos;
  }

}
