/*
  Chris Groce
  Kevin McGinn
  Nick Taylor

  CSE20212

  Final Revision: 5/2/2012

  Basic.h

  This is the interface for the Basic class, which inherits from Tower

  The Basic tower has decent range, power, and firing rate.
  */

#ifndef BASIC_H
#define BASIC_H

#include "Tower.h"

class Basic : public Tower {            // inherits from the Tower base class

public:
    Basic(int placeX, int placeY);      // constructor takes location of the tower on the screen
    void fire(Enemy *);                 // inflicts damage on enemy based on its type

};

#endif // BASIC_H
