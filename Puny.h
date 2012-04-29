/*
Project Group: Chris Groce, Kevin McGinn, Nick Taylor
CSE 20212
3/20/2012

Puny.h

This is the interface for the Puny class,
which inherits from Enemy

*/

#ifndef PUNY_H
#define PUNY_H

#include "Enemy.h"

using namespace std;

//class definition
class Puny : public Enemy {

 public:
  Puny(int startX, int startY, int wave); //constructor
  virtual void takeDamage(int unchangedDamage, char type); //have enemy take damage
  
};

#endif
