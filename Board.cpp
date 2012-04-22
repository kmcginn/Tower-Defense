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

using namespace std;

Board::Board(const char * filename)    // constructor takes file to be read as a parameter
{
  //initialize variables
  readError = 0;
  enemiesMoving = 0;

  //populate list with enemies (for now, just one)
  enemyList.push_back(new Puny(1, 0));


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
    return (towerList.size())
}

vector<vector<char> > Board::getGrid(){        // returns the grid as a vector of vector of char
    return grid;
}
