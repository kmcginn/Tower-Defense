/*
Project Group: Chris Groce, Kevin McGinn, Nick Taylor
CSE 20212
3/20/2012

Tower.h

This is the interface for the Tower abstract base class

*/
#ifndef TOWER_H
#define TOWER_H

using namespace std;

class Tower
{
   public:
	
	Tower(int x, int y);					// NOTE!! do be sure to remove all 	
	virtual void display() = 0;				// names of variable from header file
	int getPosX();
	int getPosY();
	int getFiringRate();
	int getPower();
	int sell();				// returns 3/4 of yo money
	virtual void Fire() = 0;
	void upgradePower(int upgradeCost);
	void upgradeFiringRate(int upgradeCost); 		// the image will also be updated by 
								//the display function, based on power and rate

   private:
    	int power;
	int firingRate;
	int cost;
	int xPos;
	int yPos;
	
};


#endif
