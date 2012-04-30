#include "Fire.h"
#include "Tower.h"
#include "Enemy.h"

using namespace std;

Fire::Fire(int posX, int posY) : Tower(posX,posY){
    setFiringRate(6);
    setRange(5);
    setPower(2);
    setType('f');
}

void Fire::fire(Enemy * target) {
    target->takeDamage(this->getPower(), this->getType());
}

