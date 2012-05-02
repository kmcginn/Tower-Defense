#include "Fire.h"
#include "Tower.h"
#include "Enemy.h"

using namespace std;

Fire::Fire(int posX, int posY) : Tower(posX,posY){ // basic constructor for fire tower
    // set initial values
    setFiringRate(6);
    setRange(4);
    setPower(4);
    setType('f');
}

void Fire::fire(Enemy * target) { // fire function for fire tower
    target->takeDamage(this->getPower(), this->getType());
}

