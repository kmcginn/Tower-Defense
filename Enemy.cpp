/*
Project Group: Chris Groce, Kevin McGinn, Nick Taylor
CSE 20212
3/25/2012

Enemy.cpp

This is the implementation for the Enemy abstract base class

*/

Enemy::Enemy(int startX, int startY) {

  xPos = startX;
  yPost = startY;

}

int Enemy::getPosX() {
  return xPos;
}

int Enemy::getPosY() {
  return yPos;
}

int Enemy::isDead(){
  return(health<=0);
}

int Enemy::getSpeed() {
  return speed;
}

int Enemy::getHealth() {
  return health;
}

int Enemy::getMaxHealth() {
  return maxHealth;
}

int Enemy::loseHealth(int damageTaken) {
  health -= damageTaken;
}
