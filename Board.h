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
  int findTower(int, int); // returns pointer to tower based on location
  void sellTower(int); //returns 3/4 tower cost, removes tower at given index from TowerList

  int isMoving(); //returns whether or not the enemies/towers are moving
  void startMoving(); //causes the enemies/towers to start moving
  void stopMoving(); //causes the enemies/towers to stop moving

  Enemy * getEnemy(int); //returns enemy at index in enemy list
  int enemyListSize(); //returns size of enemy list
  void addEnemy(char); //adds an enemy to the board of the specifed type
  void removeEnemy(int, int); //removes the enemy from the board at the given index in the list, adds money if player killed enemy

  Tower * getTower(int); //returns the tower at index in tower list
  int towerListSize(); //returns size of tower list

  vector<vector<char> > getGrid(); //returns the grid underlying the board
  void setGrid(char,int,int); // set grid spot to some char

  void basicTowerClick(); // the basic tower button has been clicked
  int isBasicTowerButtonClicked(); // returns value of basicTowerButton
  void quickTowerClick(); //indicates the quickTowerButton has been clicked
  int isQuickTowerButtonClicked(); //returns vales of quickTowerButton
  void fireTowerClick();
  int isFireTowerButtonClicked();
  int isTowerClicked(); //returns if a tower is clicked
  Tower * getTowerClicked(); //returns tower that is currently clicked
  int getTowerClickedIndex(); //returns index in TowerList of tower that is currently clicked
  void setTowerClicked(int); // sets towerClicked to inputted int

  int getWave(); // returns wave number
  void nextWave(); //increments wave by one
  int isWaveDone(int); //checks if wave is done based off of number of enemies already sent
  void setWaveDone(); //switches waveDone between 0 and 1
  int getNumSpawned(); //returns number of enemies spawned in current wave
  void nextSpawned(); //increment number of enemies spawned by one
  void resetNumSpawned(); //sets numSpawned back to one;

  int getMoney();
  void addMoney(int);
  void loseMoney(int);

  int getLives();
  void addLife();
  void loseLife();

 private:
  //data
  vector< Enemy* > enemyList; //list of enemies
  vector< Tower*> towerList; //list of towers
  vector<vector<char> > grid;//grid that represents the board
                            // 1 for tower option, -1 for enemy,
                           // 0 for nothing. or something 
  int readError; //boolean, whether or not there was an error reading map
  int enemiesMoving; //boolean, whether or not enemies are movin
  int basicTowerButton; // boolean, whether or not the basic tower button is clicked
  int quickTowerButton; //boolean, whether or not the quick tower button is clicked
  int fireTowerButton; //boolean, whether or not the fire tower button is clicked
  int towerClicked; // what tower is clicked, -1 for none
  int wave; //wave number
  int waveDone; //whether or not the wave is done
  int numSpawned; //number of enemies spawned so far, within wave
  int money; //amount of money the player has for building and upgrading towers
  int lives; //number of lives player has left
};
  
#endif
