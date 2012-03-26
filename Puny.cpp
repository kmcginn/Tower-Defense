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

Puny::Puny(int startX, int startY) : Enemy(startX, startY) {
  
}

void Puny::display() {

}

void Puny::takeDamage(int unchangedDamage, char type) {

  loseHealth(unchangedDamage);

}
