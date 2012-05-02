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

//#define DEBUG //flag for debugging

Tower::Tower(int x, int y) { // base class tower constructor
    //initialize values
    xPos=x;
    yPos=y;
    towerType = 'b';
    rangeCost=50;
    powerCost=50;
    firingRateCost=50;
    cost=100;
}

int Tower::getPosX(){ // returns the x position
    return xPos;
}

int Tower::getPosY(){ // returns the y position
    return yPos;
}

int Tower::getFiringRate(){ // returns the firing rate
    return firingRate;
}

int Tower::getPower(){ // returns the power
    return power;
}

int Tower::sell(){	// returns 3/4 of yo money
    return cost*3/4;
}

void Tower::setFiringRate(int rate){ //sets firing rate to inputted amount
    firingRate=rate;
}

void Tower::setPower(int pow){ // sets power to inputted amount
    power=pow;
}

void Tower::setRange(int dist){ // sets range to inputted amount
    range=dist;
}

void Tower::setType(char myType) { // sets type to inputted char
    towerType = myType;
}

int Tower::getRange(){ // returns range
    return range;
}

char Tower::getType() { // returns type
    return towerType;
}

void Tower::upgradePower(){ // upgrades the power
    power*=2; // increase power
    cost+=powerCost; // increase total cost of tower
    powerCost*=2; // increase the upgrade cost for power
#ifdef DEBUG
    cerr << "Power: " << power << endl;
#endif
}

void Tower::upgradeFiringRate(){ // upgrades the firing rate
    if (firingRate>1) { // if firing rate is greater than one
        firingRate-=1; // increase firing rate (its in terms of ticks to wait between shots)
        cost+=firingRateCost; // increase total cost of tower
        firingRateCost*=2; // increase cost of upgrade

    }
    else {
        cout << "You can upgrade firing rate any more" << endl;
    }
#ifdef DEBUG
    cerr << "firingRate: " << firingRate << endl;
#endif
}

void Tower::upgradeRange(){ // upgrades range
    range+=1; // increase range
    cost+=rangeCost; // increase total cost of tower
    rangeCost*=2; // increase upgrade cost
#ifdef DEBUG
    cerr << "Range: " << range << endl;
#endif

}

int Tower::isInRange(Enemy *creeper) { // checks if an inputted enemy is within range
    if (sqrt(pow(xPos-creeper->getPosX(),2)+pow(yPos-creeper->getPosY(),2))<=range) // distance formula
        return 1;
    else
        return 0;
}

int Tower::getCost() { // returns cost of the tower
    return cost;
}

int Tower::getFRCost() { // returns cost of upgrading the firing rate
    return firingRateCost;
}

int Tower::getPCost() { //returns cost of upgrading the power
    return powerCost;
}

int Tower::getRCost() { // returns cost of upgrading the range
    return rangeCost;
}
