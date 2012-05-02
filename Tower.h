/*
Project Group: Chris Groce, Kevin McGinn, Nick Taylor
CSE 20212
3/20/2012

Tower.h

This is the interface for the Tower abstract base class

The Tower base class contains the information and functions common
to all of the derived tower types, such the tower's location and functions
for upgrading different properties
*/
#ifndef TOWER_H
#define TOWER_H

#include "Enemy.h"

using namespace std;

class Tower
{
   public:
	
    Tower(int , int );      // constructor takes location of tower on grid
    int getPosX();          // returns tower X position
        int getPosY();      // returns tower Y position
        int getFiringRate();        // returns tower firing rate
        int getPower();         // returns tower power
    int getRange();         // returns tower range
    char getType();         // returns tower type
    int getCost();          // returns tower cost
    int getFRCost();        // retuns firing rate upgrade cost
    int getPCost();         // returns power upgrade cost
    int getRCost();         // retuns range upgrade cost
        int sell();				// returns 3/4 the total tower cost
    void setFiringRate(int);        // assigns a value to the firing rate
    void setPower(int);             // assigns a value to the power
    void setRange(int);             // assigns a value to the range
    void setType(char);             // assigns the type of tower
    virtual void fire(Enemy *) = 0;     // virtual fuction that inflicts health from an enemy
    void upgradePower();            // increases the tower's power
    void upgradeFiringRate();       // increases the tower's firing rate
    void upgradeRange();            // increases the tower's range
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
