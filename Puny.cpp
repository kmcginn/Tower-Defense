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
#include <cmath>

using namespace std;

Puny::Puny(int startX, int startY, int wave) : Enemy(startX, startY) {        // constructor; uses member initialization sytax to create an enemy of
    initHealth(15*pow(1.5,wave-1));                                                 // type "Puny"
    initType('p');
}


void Puny::takeDamage(int unchangedDamage, char type) {             // causes the ememy to take damage of specified type

  loseHealth(unchangedDamage); //takes raw damage, regardless of type

}
