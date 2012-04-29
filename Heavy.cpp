/*
  Kevin McGinn
  Chris Groce
  Nick Taylor

  CSE 20212
  4/24/2012

  Heavy.cpp

  This is the implementation for the Heavy class, which inherits from Enemy
  */

#include "Enemy.h"
#include "Heavy.h"
#include <cmath>
using namespace std;

Heavy::Heavy(int startX, int startY, int wave) : Enemy(startX, startY) {        // constructor; uses member initialization sytax to create an enemy of
    initHealth(30*pow(1.5,wave-1)); //double health of puny                           // type "Heavy"
    initSpeed(20); //half speed of puny
}


void Heavy::takeDamage(int unchangedDamage, char type) {             // causes the ememy to take damage of specified type

  loseHealth(unchangedDamage/2); //takes half of raw damage

}
