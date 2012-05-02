#ifndef BASIC_H
#define BASIC_H

#include "Tower.h"

class Basic : public Tower {            // inherits from the Tower base class

public:
    Basic(int placeX, int placeY);      // constructor takes location of the tower on the screen
    void fire(Enemy *);                 // inflicts damage on enemy based on its type

};

#endif // BASIC_H
