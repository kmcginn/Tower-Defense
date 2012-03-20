/*
Project Group: Chris Groce, Kevin McGinn, Nick Taylor
CSE 20212
3/20/2012

Board.h

This is the interface for the Board class

*/

#ifndef BOARD_H
#define BOARD_H

#include<vector>
#include"Tower.h"
#include"Enemy.h"

using namespace std;

class Board
{
 public:
  Board();
  void initMap(const char *);// NOTE!! do be sure to remove all 	
  virtual void display() = 0;// names of variable from header file
    
 private:
  int height;
  int width;
  vector< * Enemy> enemyList;
  vector< * Tower> towerList;
  vector<vector<int> grid; // 1 for tower option, -1 for enemy, 
                           // 0 for nothing. or something 
  
};
  
#endif
