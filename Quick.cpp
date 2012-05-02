/* Chris Groce
   Kevin McGinn
   Nick Taylor
    Final Draft: 5/2/2012
    Quick.cpp

    Implementation file for the quick tower, which inherits from tower

    The quick tower shots slightly faster, but is less powerful*/


#include"Quick.h"
#include"Tower.h"
#include "Enemy.h"

using namespace std;

Quick::Quick(int posX, int posY) : Tower(posX,posY){// basic quick tower constructor
    // intialize values
    setFiringRate(5);
    setRange(5);
    setPower(1);
    setType('q');
}

void Quick::fire(Enemy * target) { // fire function for quick tower
    target->takeDamage(this->getPower(), this->getType());
}
