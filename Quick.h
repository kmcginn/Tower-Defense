//header here later
#ifndef QUICK_H
#define QUICK_H

#include "Tower.h"

class Quick : public Tower {

public:
    Quick(int placeX, int placeY);
    void fire(Enemy *);

};


#endif // QUICK_H
