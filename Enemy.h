/*
Project Group: Chris Groce, Kevin McGinn, Nick Taylor
CSE 20212
3/20/2012

Enemy.h

This is the interface for the Enemy abstract base class

*/

#ifndef ENEMY_H
#define ENEMY_H

using namespace std;

class Enemy
{
 public:
  
  Enemy(int startX, int startY);// NOTE!! do be sure to remove all 	
  virtual void display() = 0;	// names of variable from header file
  virtual void takeDamage(int unchangeddamage, char type) = 0;
  void move();
  int getPosX();
  int getPosY();
  int isDead();
  
  
 private:
  int maxHealth;
  int health;
  int speed;
  int xPos;
  int yPos;
  
};
#endif
