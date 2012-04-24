/*
  Kevin McGinn
  Chris Groce
  Nick Taylor

  CSE 20212
  4/24/2012

  Speedy.h

  This is the interface for the Speedy class, which inherits from Enemy
  */

#ifndef SPEEDY_H
#define SPEEDY_H

#include "Enemy.h"

using namespace std;

//class definition
class Speedy : public Enemy {

 public:
  Speedy(int startX, int startY); //constructor
  virtual void takeDamage(int unchangedDamage, char type); //have enemy take damage

};

#endif // SPEEDY_H
