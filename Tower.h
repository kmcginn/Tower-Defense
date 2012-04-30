/*
Project Group: Chris Groce, Kevin McGinn, Nick Taylor
CSE 20212
3/20/2012

Tower.h

This is the interface for the Tower abstract base class

*/
#ifndef TOWER_H
#define TOWER_H

#include "Enemy.h"

using namespace std;

class Tower
{
   public:
	
    Tower(int , int );
    int getPosX();
	int getPosY();
	int getFiringRate();
	int getPower();
    int getRange();
    char getType();
    int getCost();
    int getFRCost();
    int getPCost();
    int getRCost();
	int sell();				// returns 3/4 of yo money
    void setFiringRate(int);
    void setPower(int);
    void setRange(int);
    void setType(char);
    virtual void fire(Enemy *) = 0;
    void upgradePower();
    void upgradeFiringRate();
    void upgradeRange();
    int isInRange(Enemy *); // returns boolean for whether an enemy is within range
                                // the image will also be updated by
                            //the display function, based on power and rate

   private:
    int power;
    int firingRate; // The smaller the faster. Will mod clock by it to determine firing rate
    int range;
	int cost;
	int xPos;
	int yPos;
    int firingRateCost; //upgrade cost for firingRate
    int powerCost; //upgrade cost for power
    int rangeCost; // upgrade cost for range
    char towerType;
};


#endif
