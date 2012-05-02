/*
  Kevin McGinn
  Chris Groce
  Nick Taylor

  CSE 20212
  4/24/2012

  Speedy.h

  This is the interface for the Speedy class, which inherits from Enemy

  The Speedy enemy moves very quickly, but has low health. It takes extra damage from Quick
  towers, but less damage from Heavy towers.
  */

#ifndef SPEEDY_H
#define SPEEDY_H

#include "Enemy.h"

using namespace std;

//class definition
class Speedy : public Enemy {

 public:
  Speedy(int startX, int startY, int wave); //constructor
  virtual void takeDamage(int unchangedDamage, char type); //have enemy take damage

};

#endif // SPEEDY_H
