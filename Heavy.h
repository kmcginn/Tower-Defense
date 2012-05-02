#ifndef HEAVY_H
#define HEAVY_H

#include "Enemy.h"

using namespace std;

//class definition
class Heavy : public Enemy {

 public:
  Heavy(int startX, int startY, int wave); // constructor takes enemy position and the wave number
  virtual void takeDamage(int unchangedDamage, char type); // have enemy take damage

};

#endif // HEAVY_H
