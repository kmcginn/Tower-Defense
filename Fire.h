#ifndef FIRE_H
#define FIRE_H

#include "Tower.h"

class Fire : public Tower {

public:
    Fire(int placeX, int placeY);
    void fire(Enemy *);

};

#endif // FIRE_H
