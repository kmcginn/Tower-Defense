//Add header later

#include"Quick.h"
#include"Tower.h"

using namespace std;

Quick::Quick(int posX, int posY) : Tower(posX,posY){
    setFiringRate(10);
    setRange(5);
    setPower(2);
}

void Quick::display() {
}

void Quick::fire() {

}
