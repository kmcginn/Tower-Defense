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
// initial positioin of enemy, stored as x and y
  xPos = startX;
  yPos = startY;
  xPrev = startX;
  yPrev = startY;
//default values, can be changed by child classes
  health = 10;
  maxHealth = 10;
  speed = 20;
  enemyType = 'p';
  enemyValue = 50;
}

int Enemy::getPosX() { // returns x position of enemy
  return xPos;
}

int Enemy::getPosY() { // returns y position of enemy
  return yPos;
}

int Enemy::isDead(){ // returns 1 if enemy is dead
  return(health<=0);
}

int Enemy::getSpeed() { // returns speed of enemy
  return speed;
}

int Enemy::getEnemyValue(){ // returns the value of the enemy
    return enemyValue;
}

void Enemy::initHealth(int startHealth) { // initializes the health to the inputted amount
    health = startHealth;
    maxHealth = startHealth;
}

void Enemy::initSpeed(int startSpeed) { // initializes the speed to the inputted amount
    speed = startSpeed;
}

void Enemy::initType(char startType) { // initializes the type to the inputted char
    enemyType = startType;
}

void Enemy::initValue(int startValue) { // initializes teh value to the inputted value
    enemyValue = startValue;
}

int Enemy::getHealth() { // returns health of enemy
  return health;
}

int Enemy::getMaxHealth() { // returns the maximum health
  return maxHealth;
}

char Enemy::getEnemyType() { // returns the enemy's type
    return enemyType;
}

void Enemy::loseHealth(int damageTaken) { // depletes health of enemy
  health -= damageTaken;
}

char Enemy::nextSpace(vector<vector<char> > map) { // determines the next space for the ememy without moving it

    if(yPos < map.size() && xPos < map[0].size()) { //ensure that movement down and right is within bounds of board

        if((map[yPos+1][xPos] == 'P' || map[yPos+1][xPos] == 'B') && yPos+1 != yPrev) {
            return 'd';                                   // next position is down
        }

        else if( (map[yPos][xPos+1] == 'P' || map[yPos][xPos+1] == 'B' )&& xPos+1 != xPrev) {
            return 'r';                                   // next position is right
        }

        else if( yPos > 0 && xPos > 0) { //ensure movement up and left is within bounds of board

            if( (map[yPos-1][xPos] == 'P' || map[yPos-1][xPos] == 'B') && yPos-1 != yPrev) {
                return 'u';                                   // next position is up
            }

            else if((map[yPos][xPos-1] == 'P' || map[yPos][xPos-1] == 'B' )&& xPos-1 != xPrev) {
                return 'l';                                   // next position is left
            }
        }

    }
}



void Enemy::move(vector<vector<char> > map) { // moves enemy one space forward along the path

    //cerr << "Size of first dimension:" << map.size() << endl; //20 y
    //cerr << "Size of second dimension:" << map[0].size() << endl; //25 x

    if(yPos < map.size() && xPos < map[0].size()) { //ensure that movement down and right is within bounds of board

        if((map[yPos+1][xPos] == 'P' || map[yPos+1][xPos] == 'B') && yPos+1 != yPrev) {
            yPrev = yPos++;                                   // next position is down
            xPrev = xPos;
        }

        else if( (map[yPos][xPos+1] == 'P' || map[yPos][xPos+1] == 'B' )&& xPos+1 != xPrev) {
            xPrev = xPos++;                                   // next position is right
            yPrev = yPos;
        }

        else if( yPos > 0 && xPos > 0) { //ensure movement up and left is within bounds of board

            if( (map[yPos-1][xPos] == 'P' || map[yPos-1][xPos] == 'B') && yPos-1 != yPrev) {
                yPrev = yPos--;                                   // next position is up
                xPrev = xPos;
            }

            else if((map[yPos][xPos-1] == 'P' || map[yPos][xPos-1] == 'B' )&& xPos-1 != xPrev) {
                xPrev = xPos--;                                   // next position is left
                yPrev = yPos;
            }
        }

    }
}
