//header here later
#ifndef QUICK_H
#define QUICK_H

#include "Tower.h"

class Quick : public Tower {        // inherits from  Tower base class

public:
    Quick(int placeX, int placeY);  // Constructor takes x and y position for the tower
    void fire(Enemy *);     // inflicts enemies with damage based on their type

};


#endif // QUICK_H
