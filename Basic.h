#ifndef BASIC_H
#define BASIC_H

#include "Tower.h"

class Basic : public Tower {

public:
    Basic(int placeX, int placeY);
    void fire(Enemy *);

};

#endif // BASIC_H
