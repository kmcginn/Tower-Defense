/*
Project Group: Chris Groce, Kevin McGinn, Nick Taylor
CSE 20212
3/20/2012

Puny.h

Final Revision: 5/2/2012

This is the interface for the Puny class,
which inherits from Enemy

The Puny enemy moves at a normal speed, and takes normal damage from all Towers

*/

#ifndef PUNY_H
#define PUNY_H

#include "Enemy.h"

using namespace std;

//class definition
class Puny : public Enemy {

 public:
  Puny(int startX, int startY, int wave); // Constructor takes x and y position and wave number
  virtual void takeDamage(int unchangedDamage, char type); //have enemy take damage
  
};

#endif
