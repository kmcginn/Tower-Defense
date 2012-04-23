/*
Project Group: Chris Groce, Kevin McGinn, Nick Taylor
CSE 20212
3/20/2012

Puny.cpp

This is the implementation for the Puny class,
which inherits from Enemy

*/

#include "Enemy.h"
#include "Puny.h"

using namespace std;

Puny::Puny(int startX, int startY) : Enemy(startX, startY) {        // constructor; uses member initialization sytax to create an enemy of
    initHealth(15);                                                 // type "Puny"
}


void Puny::takeDamage(int unchangedDamage, char type) {             // causes the ememy to take damage of specified type

  loseHealth(unchangedDamage);

}
