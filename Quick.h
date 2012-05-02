/*
  Chris Groce
  Kevin McGinn
  Nick Taylor

  CSE20212

  Final Revision: 5/2/2012

  Quick.h

  This is the interface for the Quick class, which inherits from Tower

  The Quick tower starts off with a faster rate of fire, but lower power

  */
#ifndef QUICK_H
#define QUICK_H

#include "Tower.h"

class Quick : public Tower {        // inherits from  Tower base class

public:
    Quick(int placeX, int placeY);  // Constructor takes x and y position for the tower
    void fire(Enemy *);     // inflicts enemies with damage based on their type

};


#endif // QUICK_H
