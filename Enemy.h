/*
Project Group: Chris Groce, Kevin McGinn, Nick Taylor
CSE 20212
3/20/2012

Enemy.h

This is the interface for the Enemy abstract base class

*/

#ifndef ENEMY_H
#define ENEMY_H

#include <vector>

using namespace std;

class Enemy
{
 public:
  
  Enemy(int, int); //constructor
  //member functions
  virtual void takeDamage(int, char) = 0; //take damage of raw value and type (pure virtual)
  char nextSpace(vector<vector<char > >); //determines enemy's next space without moving it'
  void move(vector<vector<char> >); //moves the enemy to next spot on path
  int getPosX(); //returns x position of enemy
  int getPosY(); //returns y position of enemy
  int isDead(); //returns whether or not enemy is dead
  int getSpeed(); //returns speed of the enemy
  int getHealth(); //returns health of the enemy
  int getMaxHealth(); //returns max health of the enemy
  void initHealth(int); //initializes enemy health
  void initSpeed(int); //initializes enemy speed

 private:

  //data
  int maxHealth;
  int health;
  int speed; //NOTE: LOWER NUMBER IS FASTER; speed corresponds to how many frames it takes for enemy to move one tile
  int xPos; //current x position
  int yPos; //current y position
  int xPrev; //previous x position
  int yPrev; //previous y position


protected:
  void loseHealth(int); //enemy loses inputted amount of health
};
#endif
