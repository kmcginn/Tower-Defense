/* Chris Groce
   Kevin McGinn
   Nick Taylor
    Final Draft: 5/2/2012

    Heavy.cpp

    Implementation file for the Heavy enemy, which inherits from Enemy.h

    The Heavy enemy moves slower than Puny, but has double the health and
    take reduced damage from both quick and basic towers. It takes double
    damage from fire towers though*/

#include "Enemy.h"
#include "Heavy.h"
#include <cmath>
using namespace std;

Heavy::Heavy(int startX, int startY, int wave) : Enemy(startX, startY) { // constructor; uses member initialization sytax to create an enemy of
    //initialize values
    initHealth(30*pow(1.5,wave-1)); //double base health of puny                           // type "Heavy"
    initSpeed(40); //half speed of puny
    initType('h');
    initValue(25*((wave+3)/3)); // increment value by 25 every 5 waves
}


void Heavy::takeDamage(int unchangedDamage, char type) { // causes the ememy to take damage of specified type

    if(type == 'b'){ // if tower is  basic
        loseHealth(unchangedDamage/2); //takes half of normal damage
    }
    else if(type == 'q') { // if tower is quick
        loseHealth(unchangedDamage/4); //takes a quarter of "quick" damage

    }
    else if(type == 'f') { // if tower is double
        loseHealth(unchangedDamage*2); //takes DOUBLE fire damage
    }
    else {
        loseHealth(unchangedDamage); //normal damage otherwise
    }
}
