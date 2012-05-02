/*
  Chris Groce
  Kevin McGinn
  Nick Taylor

  CSE20212

  Final Revision: 5/2/2012

  Fire.h

  This is the interface for the Fire class, which inherits from Tower

  The Fire tower has great power, but lower range
  */

#ifndef FIRE_H
#define FIRE_H

#include "Tower.h"

class Fire : public Tower {         // inherits from tower base class

public:
    Fire(int placeX, int placeY);       // constructor takes location of tower on screen
    void fire(Enemy *);             // inflicts damage on an ememy based on its type

};

#endif // FIRE_H
