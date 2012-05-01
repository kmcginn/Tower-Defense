/* Nick Taylor
   Board.cpp - Board class file
   Final Project
   CSE20212 */

#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>
#include <string>
#include <cstdlib>
#include <QString>
#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include "Board.h"
#include "Enemy.h"
#include "Puny.h"
#include "Heavy.h"
#include "Speedy.h"
#include "Quick.h"

using namespace std;

Board::Board(const char * filename)    // constructor takes file to be read as a parameter
{
  //initialize variables
  readError = 0;
  enemiesMoving = 0;
  basicTowerButton = 0;
  quickTowerButton = 0;
  fireTowerButton = 0;
  towerClicked=-1;
  numSpawned=0;
  wave=1;
  waveDone=1;
  money = 300;

  //populate list with enemies (for now, just one)
  //enemyList.push_back(new Puny(1, 0));

  //FOR TESTING ONLY
  //adds towers to the list to make sure they display
  //towerList.push_back(new Quick(3, 1));

  vector<char> tempVec;
  //convert filename to QString
  QString inputtedFile(filename);
  
  //get file
  QFile inputFile(inputtedFile);

  //if fails to open file (opened in if statement)
  if(!inputFile.open(QIODevice::ReadOnly)) { // checks that file exists and has content
      cout << "Unable to open file" << endl;
      readError = 1;
  }

  //opened successfully
  else{
    //make a QTextStream from the file
    QTextStream in(&inputFile);
    //go through the whole stream
    while(!in.atEnd()) {
        //get each line
          QString line = in.readLine();

         //store each part of line in tempVec
         for(int i = 0; i < line.length(); i++)
          {
            tempVec.push_back(line[i].toAscii());
        }
         //store row in grid
        grid.push_back(tempVec);
        //get rid of data in tempVec
        tempVec.erase(tempVec.begin(), tempVec.end());
    }
  }

  //close the file
  inputFile.close();
}

//returns whether or not the map file failed to be read
int Board::readFail() {
  return readError;
}

//returns horizontal size of board
int Board::getHoriz() {

  return grid[0].size();

}

//returns vertical size of board
int Board::getVert() {
  return grid.size();

}

void Board::gridPrint()                         // prints the grid to the command window (for terminal testing)
{
  for(int row = 0; row < grid.size(); row++)
  {
    for(int col = 0; col < grid[row].size(); col++)
    {  
      cout << grid[row][col] << " ";
    }
    cout << endl;
  }
} 

char Board::getCell(int row, int col){          // returns the character in the given grid location
    return(grid[row][col]);
}

int Board::isMoving() {                         // returns true if enemy is moving
    return enemiesMoving;
}

void Board::startMoving(){                      // causes enemies to start moving
    enemiesMoving = 1;
}

void Board::stopMoving(){                       // causes enemies to stop moving
    enemiesMoving = 0;
}

Enemy * Board::getEnemy(int index) {            // returns the enemy at the index of the enemy list
    return (enemyList[index]);
}

int Board::enemyListSize(){                    // returns number of enemies

    return(enemyList.size());
}

Tower * Board::getTower(int index) {
    return(towerList[index]);
}

int Board::towerListSize() {
    return (towerList.size());
}

vector<vector<char> > Board::getGrid(){        // returns the grid as a vector of vector of char
    return grid;
}

void Board::setGrid(char type, int x, int y){
    grid[y][x]=type;
}

void Board::basicTowerClick(){ // flips basicTowerButton value, deactiaves all others
    if (basicTowerButton)
        basicTowerButton=0;
    else
        basicTowerButton=1;

    //deactivate all other buttons
    quickTowerButton = 0;
    fireTowerButton = 0;
}

int Board::isBasicTowerButtonClicked(){
    return basicTowerButton;
}

void Board::quickTowerClick() { //flips quickTowerButton value, deactivates all others
    if(quickTowerButton)
        quickTowerButton = 0;
    else
        quickTowerButton = 1;

    //deactivate all other buttons
    basicTowerButton = 0;
    fireTowerButton = 0;

}

int Board::isQuickTowerButtonClicked(){
    return quickTowerButton;
}

void Board::fireTowerClick() {
    if(fireTowerButton)
        fireTowerButton = 0;
    else
        fireTowerButton = 1;

    //deactivate all other buttons
    basicTowerButton = 0;
    quickTowerButton = 0;
}

int Board::isFireTowerButtonClicked(){
    return fireTowerButton;
}

void Board::addTower(Tower * newTower) {
    if(this->getMoney() >= newTower->getCost()) {
        towerList.push_back(newTower);
        setGrid('T',newTower->getPosX(),newTower->getPosY());
        loseMoney(newTower->getCost());
    }
    else {
        cerr << "You don't have enough money!" << endl; //NOTE: CHANGE THIS TO POPUP?
    }
}

int Board::findTower(int x, int y){
    for (int i=0; i<towerList.size(); i++) {
        Tower * temp=towerList[i];
        if(temp->getPosX()==x && temp->getPosY()==y) {
            return i;
        }
    }
    return -1;
}

int Board::isTowerClicked(){
    if (towerClicked==-1) return 0;
    else return 1;
}

Tower * Board::getTowerClicked() {
    return towerList[towerClicked];
}

void Board::setTowerClicked(int num) {
    towerClicked=num;
}

void Board::addEnemy(char type) {
    if (type=='p')
        enemyList.push_back(new Puny(1, 0, wave));
    else if (type=='h')
        enemyList.push_back(new Heavy(1, 0, wave));
    else if (type=='s')
        enemyList.push_back(new Speedy(1, 0, wave));

}

int Board::getWave() {
    return wave;
}

void Board::nextWave() {
    wave+=1;
}

int Board::isWaveDone(int numEnemy) {
    if (numEnemy<10&&waveDone==0)
        return 0;
    else
        return 1;
}

void Board::setWaveDone() {
    int temp=waveDone;
    if (temp==1){
        waveDone=0;
    }
    else{
        waveDone=1;
    }
}

int Board::getNumSpawned(){
    return numSpawned;
}

void Board::nextSpawned() {
    numSpawned+=1;
}

void Board::resetNumSpawned() {
    numSpawned=0;
}

int Board::getMoney() {
    return money;
}

void Board::addMoney(int amt) {
    money+=amt;
}

void Board::loseMoney(int amt) {
    money-=amt;
}
