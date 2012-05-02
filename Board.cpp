/*
Project Group: Chris Groce, Kevin McGinn, Nick Taylor
CSE 20212
Final Draft: 5/2/2012

Board.cpp

This is the implementation file for Board.h

This class includes all of the information for playing the game. It
has a vector of all of the enmeies on the board and all of the towers.
There are many miscellaneous function to help different aspects of the
game such as waves and buttons.

*/

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

//#define DEBUG //flag for debugging

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
  lives = 5;

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

void Board::removeEnemy(int index, int wasSlain) { //removes enemy at the given index, gives player money if player killed enemy

    if(wasSlain) {
        //add money based on enemy's worth
        addMoney(getEnemy(index)->getEnemyValue());
    }
    //remove enemy from list
    enemyList.erase(enemyList.begin()+index);

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
#ifdef DEBUG
        cerr << "You don't have enough money!" << endl; //NOTE: CHANGE THIS TO POPUP?
#endif
    }
}

int Board::findTower(int x, int y){ // find tower based on grid location
    for (int i=0; i<towerList.size(); i++) { // march through tower list
        Tower * temp=towerList[i]; // create temp
        if(temp->getPosX()==x && temp->getPosY()==y) { // check if location is correct
            return i;
        }
    }
    return -1;
}

void Board::sellTower(int index) { //refunds 3/4 the cost of tower at given index, removes it from towerList
    addMoney(getTower(index)->getCost()*3/4); //refund 3/4 the cost
    towerList.erase(towerList.begin()+index); //remove tower from the list
}

int Board::isTowerClicked(){ // checked if a tower is clicked
    if (towerClicked==-1) return 0;
    else return 1;
}

Tower * Board::getTowerClicked() { //returns a pointer to the clicked tower
    return towerList[towerClicked];
}

int Board::getTowerClickedIndex() { // returns the index of the tower clicked within the tower list
    return towerClicked;
}

void Board::setTowerClicked(int num) { // sets towerClicked to whatever tower's index is inputted
    towerClicked=num;
}

void Board::addEnemy(char type) { // adds an enemy onto the board
    if (type=='p') // if puny enemy is chosen
        enemyList.push_back(new Puny(1, 0, wave)); // make a puny
    else if (type=='h') // if a heavy enemy is chosen
        enemyList.push_back(new Heavy(1, 0, wave)); // make a heavy
    else if (type=='s') // if a speedy enemy is chosen
        enemyList.push_back(new Speedy(1, 0, wave)); // make a speedy

}

int Board::getWave() { // returns wave number
    return wave;
}

void Board::nextWave() { // increments wave by one
    wave+=1;
}

int Board::isWaveDone(int numEnemy) { // checks if wave is done based off of number of enemies currently spawned
    if (numEnemy<10&&waveDone==0) // if number of enemies is less than 10
        return 0;
    else
        return 1;
}

int Board::isWaveDone() { // returns waveDone
    return waveDone;
}

void Board::setWaveDone() { // switches waveDone's value between 1 and 0
    int temp=waveDone;
    if (temp==1){
        waveDone=0;
    }
    else{
        waveDone=1;
    }
}

int Board::getNumSpawned(){ // returns number of enemies spawned
    return numSpawned;
}

void Board::nextSpawned() { // increments numSpawned by one
    numSpawned+=1;
}

void Board::resetNumSpawned() { // set numSpawned to 0
    numSpawned=0;
}

int Board::getMoney() { // returns the amount of money the player has
    return money;
}

void Board::addMoney(int amt) { // adds an inputted amount to money
    money+=amt;
}

void Board::loseMoney(int amt) { // subtracts a certain amount from money
    money-=amt;
}

int Board::getLives() { // returns number of lives
    return lives;
}

void Board::addLife(){ // adds a life as long as there are no more than ten currently
    if(getLives() < 10){
        lives++;
    }
}

void Board::loseLife() { // subtracts one live as long as it's not already zero
    if(lives > 0)
        lives--;
}
