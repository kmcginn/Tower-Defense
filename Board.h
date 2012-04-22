/*
Project Group: Chris Groce, Kevin McGinn, Nick Taylor
CSE 20212
3/20/2012

Board.h

This is the interface for the Board class

X = place for tower
P = place for enemy
H = place for nothing (hole)

*/

#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Tower.h"
#include "Enemy.h"

using namespace std;

class Board
{
 public:
  Board(const char *);
  void initMap(); //initializes the map; currently unused
  void display();
  void gridPrint(); //prints the grid to the terminal (for testing)
  int readFail(); //returns whether or not reading the map failed
  int getHoriz(); //returns number of cells horizontally
  int getVert(); //returns number of cells vertically
  char getCell(int, int); //returns content of cell in grid
  void addTower(Tower *); //adds tower pointer to towerlist

  int isMoving(); //returns whether or not the enemies/towers are moving
  void startMoving(); //causes the enemies/towers to start moving
  void stopMoving(); //causes the enemies/towers to stop moving
  Enemy * getEnemy(int); //returns enemy at index in enemy list
  int enemyListSize(); //returns size of enemy list
  Tower * getTower(int); //returns the tower at index in tower list
  int towerListSize(); //returns size of tower list
  vector<vector<char> > getGrid(); //returns the grid underlying the board
  void basicTowerClick(); // the basic tower button has been clicked
  int isBasicTowerClicked(); // returns value of basicTowerButton


 private:
  //data
  vector< Enemy* > enemyList; //list of enemies
  vector< Tower*> towerList; //list of towers
  vector<vector<char> > grid;//grid that represents the board
                            // 1 for tower option, -1 for enemy,
                           // 0 for nothing. or something 
  int readError; //boolean, whether or not there was an error reading map
  int enemiesMoving; //boolean, whether or not enemies are movin
  int basicTowerButton; // boolean, wether or not the basic button is clicked

};
  
#endif
