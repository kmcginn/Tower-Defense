//Add header later

#include"Quick.h"
#include"Tower.h"
#include "Enemy.h"

using namespace std;

Quick::Quick(int posX, int posY) : Tower(posX,posY){
    setFiringRate(3);
    setRange(5);
    setPower(2);
}

void Quick::fire(Enemy * target) {
    target->takeDamage(this->getPower(), 'q');
}
