
#include "Basic.h"
#include "Tower.h"
#include "Enemy.h"

using namespace std;

Basic::Basic(int posX, int posY) : Tower(posX,posY){
    setFiringRate(6);
    setRange(5);
    setPower(2);
    setType('b');
}

void Basic::fire(Enemy * target) {
    target->takeDamage(this->getPower(), this->getType());
}
