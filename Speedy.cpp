
/*
Project Group: Chris Groce, Kevin McGinn, Nick Taylor
CSE 20212
3/20/2012

Speedy.cpp

This is the implementation for the Speedy class,
which inherits from Enemy

*/

#include "Enemy.h"
#include "Speedy.h"

using namespace std;

Speedy::Speedy(int startX, int startY) : Enemy(startX, startY) {        // constructor; uses member initialization sytax to create an enemy of
    initHealth(7);                                                 // type "Puny"
    initSpeed(5);
}


void Speedy::takeDamage(int unchangedDamage, char type) {             // causes the ememy to take damage of specified type

  loseHealth(unchangedDamage);

}
