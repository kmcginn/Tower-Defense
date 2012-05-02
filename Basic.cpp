
#include "Basic.h"
#include "Tower.h"
#include "Enemy.h"

using namespace std;

Basic::Basic(int posX, int posY) : Tower(posX,posY){ //basic constuctor
    // set initial values for tower stats
    setFiringRate(6);
    setRange(5);
    setPower(2);
    setType('b');
}

void Basic::fire(Enemy * target) { // fire function
    target->takeDamage(this->getPower(), this->getType());
}
