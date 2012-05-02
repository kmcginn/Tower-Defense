//Add header later

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
