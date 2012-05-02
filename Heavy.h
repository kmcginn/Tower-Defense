/*
  Chris Groce
  Kevin McGinn
  Nick Taylor

  CSE20212

  Heavy.h

  Final Revision: 5/2/2012

  This is the interface for the Heavy class, which inherits from Enemy

  The Heavy enemy moves slowly, but has lots of health. It is also resistant to attacks
  from the Basic and Quick towers.
  */

#ifndef HEAVY_H
#define HEAVY_H

#include "Enemy.h"

using namespace std;

//class definition
class Heavy : public Enemy {

 public:
  Heavy(int startX, int startY, int wave); // constructor takes enemy position and the wave number
  virtual void takeDamage(int unchangedDamage, char type); // have enemy take damage

};

#endif // HEAVY_H
