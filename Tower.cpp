/*Chris Groce
  Tower.cpp-source file for Tower.h
  CSE20212 */

#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <QString>
#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include "Board.h"
#include "Tower.h"

Tower::Tower(int x, int y) {
    xPos=x;
    yPos=y;
    towerType = 'b';
    rangeCost=50;
    powerCost=50;
    firingRateCost=50;
    cost=100;
}

int Tower::getPosX(){
    return xPos;
}

int Tower::getPosY(){
    return yPos;
}

int Tower::getFiringRate(){
    return firingRate;
}

int Tower::getPower(){
    return power;
}

int Tower::sell(){				// returns 3/4 of yo money
    return cost*3/4;
}

void Tower::setFiringRate(int rate){
    firingRate=rate;
}

void Tower::setPower(int pow){
    power=pow;
}

void Tower::setRange(int dist){
    range=dist;
}

void Tower::setType(char myType) {
    towerType = myType;
}

int Tower::getRange(){
    return range;
}

char Tower::getType() {
    return towerType;
}

void Tower::upgradePower(){
    power+=2;
    powerCost*=2;
    cerr << "Power: " << power << endl;

}

void Tower::upgradeFiringRate(){
    if (firingRate>1) {
        firingRate-=1;
        firingRateCost*=2;
    }
    cerr << "firingRate: " << firingRate << endl;
}

void Tower::upgradeRange(){
    range+=1;
    rangeCost*=2;
    cerr << "Range: " << range << endl;

}

int Tower::isInRange(Enemy *creeper) {
    if (sqrt(pow(xPos-creeper->getPosX(),2)+pow(yPos-creeper->getPosY(),2))<=range)
        return 1;
    else
        return 0;
}

int Tower::getCost() {
    return cost;
}

int Tower::getFRCost() {
    return firingRateCost;
}

int Tower::getPCost() {
    return powerCost;
}

int Tower::getRCost() {
    return rangeCost;
}
