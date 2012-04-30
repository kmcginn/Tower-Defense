/*
 Project Group: Chris Groce, Kevin McGinn, Nick Taylor
 CSE 20212
 3/27/2012

 MyPaint.cpp

 This is the implementation for the MyPaint class, which acts
 as the display for the TowerDefense game
 */

#include "Board.h"
#include "MyPaint.h"
#include "Quick.h"
#include "Basic.h"
#include "Tower.h"
#include <QtGui>
#include <iostream>
#include <fstream>
#include <cmath>
#include <typeinfo>
#include <unistd.h>
using namespace std;


// constructor
MyPaint::MyPaint(QWidget *parent)
    : QWidget(parent), myBoard(":/map1.txt"), grassMap(":/grass_beta.png"), grassBrush(grassMap) {
     setWindowTitle(tr("Tower Defense"));
     windowHorizontal = 512;
     windowVertical = 512;
     cellDim = windowHorizontal / myBoard.getHoriz();
     numRows = myBoard.getVert();
     numCols = myBoard.getHoriz();
     resize(windowHorizontal, windowVertical);
     clock=0;
}

// This method is called when the widget needs to be redrawn.
//
void MyPaint::paintEvent(QPaintEvent *) {
    cerr << " you got: " << myBoard.getMoney() << endl;


        QPainter painter(this);  //! get a painter object to send drawing commands to
	 
	// a QPainter operates (by default) in pixel coordinates, with the origin
	// at the upper-left corner

	// Set the colors for each of the painters
	// The Pen is used to draw lines and figure outlines, while the brush is used to fill in
	// the figures

        //initialize pen
        QPen pen(Qt::black, 2, Qt::SolidLine);
	painter.setPen(Qt::black);

	//code for displaying map, only runs if map reads correctly
	if(!myBoard.readFail()) {

            //initialize variables
            char temp;
            int tileX = 0;
            int tileY = 0;


            //fill in cells
            for(int i = 0; i < numRows; i++) {
                for(int j = 0; j < numCols; j++){
                    //gets char in grid
                    temp = myBoard.getCell(i, j);
                    //change color of brush to indicate type of tile
                    switch(temp){
                        //tile is for towers
                        case 'X':
                            painter.setBrush(grassBrush);
                            break;
                        //tile is for enemies
                        case 'P':
                            painter.setBrush(Qt::yellow);
                            break;
                        //tile is for nothing (hole)
                        case 'H':
                            painter.setBrush(Qt::white);
                            break;
                        //tile is for tower
                        case 'T':
                            painter.setBrush(Qt::cyan);
                            break;
                        //tile is base
                        case 'B':
                            painter.setBrush(Qt::green);
                            break;
                        //tile is unknown type
                        default:
                            painter.setBrush(Qt::red);
                            break;
                    }

                    //draw rect at position
                    tileX = j*cellDim;
                    tileY = i*cellDim;
                    painter.drawRect(tileX, tileY, cellDim, cellDim);
                }
            }

            //display towers
            int numTowers = myBoard.towerListSize();
            Tower * tempTower;
            painter.setBrush(Qt::black);
            int drawTX = 0;
            int drawTY = 0;
            for(int i = 0; i < numTowers; i++){
                tempTower = myBoard.getTower(i);


                if(tempTower->getType() == 'b') {
                    painter.setBrush(Qt::white);
                }
                else if(tempTower->getType() == 'q') {
                    painter.setBrush(Qt::blue);
                }
                else if(tempTower->getType() == 'f'){
                    painter.setBrush(Qt::red);
                }
                else {
                    painter.setBrush(Qt::cyan); //unknown type
                }

                drawTX = cellDim*tempTower->getPosX() + cellDim/4;
                drawTY = cellDim*tempTower->getPosY() + cellDim/4;
                painter.drawRect(drawTX, drawTY, cellDim/2, cellDim/2);
            }



            //if enemies are moving, draw them
            if(myBoard.isMoving()){
                 //cerr << myBoard.isWaveDone(myBoard.getNumSpawned()) << endl;
                if (!myBoard.isWaveDone(myBoard.getNumSpawned()) && clock%20 == 1) {
                    if (myBoard.getNumSpawned()%5==0){
                        myBoard.addEnemy('h');
                    }
                    else if ((myBoard.getNumSpawned())%3==0) {
                        myBoard.addEnemy('s');
                    }
                    else {
                        myBoard.addEnemy('p');
                    }
                    myBoard.nextSpawned();
                    cerr << "spawn number: " << myBoard.getNumSpawned() << endl;
                    if (myBoard.isWaveDone(myBoard.getNumSpawned())) {
                        myBoard.resetNumSpawned();
                        myBoard.setWaveDone();
                        myBoard.nextWave();
                    }
                }
                int numTowers = myBoard.towerListSize();
                int numEnemies = myBoard.enemyListSize();
                char nxtSpot;
                Tower *tempTower;
                Enemy *tempEnemy;
                //go through all the towers
                for (int i = 0; i < numTowers; i++) {
                    //go through all the enemies
                    tempTower=myBoard.getTower(i);
                    for(int j = 0; j < numEnemies; j++) {
                        //fire at ONLY the first enemy in range
                        tempEnemy=myBoard.getEnemy(j);
                        if(tempTower->isInRange(tempEnemy) && !tempEnemy->isDead() && clock%tempTower->getFiringRate()==0) {
                            cerr << "Targeted enemy health: " << tempEnemy->getHealth() << endl;
                            tempTower->fire(tempEnemy);
                            nxtSpot = tempEnemy->nextSpace(myBoard.getGrid());
                            switch(nxtSpot){
                            case 'd':
                            painter.drawLine(tempTower->getPosX()*cellDim+cellDim/2, tempTower->getPosY()*cellDim+cellDim/2,
                                             cellDim*tempEnemy->getPosX() + cellDim/2,
                                             cellDim*tempEnemy->getPosY() + cellDim/2 +
                                             ((clock-1)%tempEnemy->getSpeed())*cellDim/(double)tempEnemy->getSpeed());
                            break;
                            case 'u':
                            painter.drawLine(tempTower->getPosX()*cellDim+cellDim/2, tempTower->getPosY()*cellDim+cellDim/2,
                                             cellDim*tempEnemy->getPosX() + cellDim/2,
                                             cellDim*tempEnemy->getPosY() + cellDim/2 -
                                             ((clock-1)%tempEnemy->getSpeed())*cellDim/(double)tempEnemy->getSpeed());
                            break;
                            case 'r':
                            painter.drawLine(tempTower->getPosX()*cellDim+cellDim/2, tempTower->getPosY()*cellDim+cellDim/2,
                                             cellDim*tempEnemy->getPosX() + cellDim/2 +
                                             ((clock-1)%tempEnemy->getSpeed())*cellDim/(double)tempEnemy->getSpeed(),
                                             cellDim*tempEnemy->getPosY() + cellDim/2);
                            break;
                            case 'l':
                            painter.drawLine(tempTower->getPosX()*cellDim+cellDim/2, tempTower->getPosY()*cellDim+cellDim/2,
                                             cellDim*tempEnemy->getPosX() + cellDim/2 -
                                             ((clock-1)%tempEnemy->getSpeed())*cellDim/(double)tempEnemy->getSpeed(),
                                             cellDim*tempEnemy->getPosY() + cellDim/2);
                            break;
                            }
                           break;
                        }
                    }
                }


                Enemy * temp;
                char nxt;
                painter.setBrush(Qt::red); //change for different enemy types in final project
                //go through all enemies
                for(int i = 0; i < numEnemies; i++) {
                    temp = myBoard.getEnemy(i);
                    if(!temp->isDead()) {
                        nxt = temp->nextSpace(myBoard.getGrid());
                        //draw ellipse to represent enemy
                        switch(nxt){
                        case 'd':
                        painter.drawEllipse(cellDim*temp->getPosX() + cellDim/4,
                                            cellDim*temp->getPosY() + cellDim/4 +((clock-1)%temp->getSpeed())*cellDim/(double)temp->getSpeed(),
                                            cellDim/2, cellDim/2 );
                        break;
                        case 'u':
                        painter.drawEllipse(cellDim*temp->getPosX() + cellDim/4,
                                            cellDim*temp->getPosY() + cellDim/4 - ((clock-1)%temp->getSpeed())*cellDim/(double)temp->getSpeed(),
                                            cellDim/2, cellDim/2 );
                        break;
                        case 'r':
                        painter.drawEllipse(cellDim*temp->getPosX() + cellDim/4 + ((clock-1)%temp->getSpeed())*cellDim/(double)temp->getSpeed(),
                                            cellDim*temp->getPosY() + cellDim/4,
                                            cellDim/2, cellDim/2 );
                        break;
                        case 'l':
                        painter.drawEllipse(cellDim*temp->getPosX() + cellDim/4 - ((clock-1)%temp->getSpeed())*cellDim/(double)temp->getSpeed(),
                                            cellDim*temp->getPosY() + cellDim/4,
                                            cellDim/2, cellDim/2 );
                        break;
                        }
                        //make the enemy move
                        if(clock%temp->getSpeed()==0)
                        temp->move(myBoard.getGrid());
                    }
                }

                usleep(50000);
                //sleep(.1); //change duration later
                if (clock>=1000){
                    clock=1;
                }
                else {
                    clock+=1;
                }
                update();
            }

            //draws the button for making the enemies move
            painter.setBrush(Qt::blue);
            painter.drawRect(cellDim, cellDim*(numRows + 2), 5*cellDim, 3*cellDim);

            //draws button for basic tower
            painter.setBrush(Qt::black);
            painter.drawRect(7*cellDim, cellDim*(numRows + 2), 2*cellDim, 2*cellDim);
                //button indicator
            if (myBoard.isBasicTowerButtonClicked()) {
                painter.setPen(Qt::red);
                painter.drawRect(7*cellDim, cellDim*(numRows + 2), 2*cellDim, 2*cellDim);
            }

            //draws upgrade buttons
            if (myBoard.isTowerClicked()) {
                painter.setBrush(Qt::white);
                painter.drawRect(20*cellDim, cellDim*(numRows+1),5*cellDim,4*cellDim);

                painter.setBrush(Qt::blue);
                painter.drawRect(21*cellDim, cellDim*(numRows+2),.9*cellDim,1*cellDim);
                painter.drawRect(22*cellDim, cellDim*(numRows+2),.9*cellDim,1*cellDim);
                painter.drawRect(23*cellDim, cellDim*(numRows+2),.9*cellDim,1*cellDim);

            }

	}

        //fails to load map
        else{
            //draw blue screen of death!
            painter.setBrush(Qt::blue);
            painter.drawRect(0, 0, windowHorizontal, windowVertical);
        }

}

// The mousePressEvent() function overrides the mousePressEvent() function of the parent QWidget
// class, and is used to capture mouse clicks (either on the button press or the button release).
void MyPaint::mousePressEvent(QMouseEvent *e) {


    int clickX = e->x()/cellDim;
    int clickY = e->y()/cellDim;
    if(onMoveButton(e->x(), e->y())){           // when move button is clicked, the enemy starts moving
            myBoard.startMoving();
            myBoard.setTowerClicked(-1);
            //cerr<<"fun: " << myBoard.isWaveDone(myBoard.getNumSpawned())<<endl;
            //cerr << myBoard.getNumSpawned() << endl;
            myBoard.setWaveDone();
            //cerr<<"fun: " << myBoard.isWaveDone(myBoard.getNumSpawned())<<endl;
            //myBoard.addEnemy('h');

    }
    else if(onBasicTowerButton(e->x(), e->y())){           // when move button is clicked, the ememy strts moving
        myBoard.basicTowerClick();
        myBoard.setTowerClicked(-1);

}
    /*
    else{
        myBoard.stopMoving();                   // a click anywhere else stops the enemy
    }
    */
    else if (myBoard.isBasicTowerButtonClicked()){ //need to check if within bounds of board, or on a path, or on a black space
        //cerr << "Clicked on the board after clicking tower button" << endl;

        //if valid square is selected (on the board, cell is an X)
        if(clickX >= 0 && clickX < numCols && clickY >= 0 && clickY < numRows && myBoard.getCell(clickY, clickX) == 'X') {
            myBoard.addTower(new Basic(clickX, clickY));
        }
        myBoard.setTowerClicked(-1);

    }
    else if (myBoard.findTower(clickX,clickY)!=-1) { // if a tower is clicked
        myBoard.setTowerClicked(myBoard.findTower(e->x()/cellDim,e->y()/cellDim));

    }
    //upgrade range button
    else if (myBoard.isTowerClicked()&& e->x()<=cellDim*21.9 && e->x()>=cellDim*21 && e->y()>=cellDim*(numRows+2) && e->y()<=cellDim*(numRows+3)) {
        if(myBoard.getMoney() >= myBoard.getTowerClicked()->getRCost()){
            myBoard.loseMoney(myBoard.getTowerClicked()->getRCost());
            myBoard.getTowerClicked()->upgradeRange();
        }
        //cerr << "an upgrade has been clicked" << endl;
    }
    else if (myBoard.isTowerClicked()&& e->x()<=cellDim*22.9 && e->x()>=cellDim*22 && e->y()>=cellDim*(numRows+2) && e->y()<=cellDim*(numRows+3)) {
        if(myBoard.getMoney() >= myBoard.getTowerClicked()->getFRCost()){
            myBoard.loseMoney(myBoard.getTowerClicked()->getFRCost());
            myBoard.getTowerClicked()->upgradeFiringRate();
        }
        //cerr << "an upgrade has been clicked" << endl;

    }
    else if (myBoard.isTowerClicked()&& e->x()<=cellDim*23.9 && e->x()>=cellDim*23 && e->y()>=cellDim*(numRows+2) && e->y()<=cellDim*(numRows+3)) {
        if(myBoard.getMoney() >= myBoard.getTowerClicked()->getPCost()){
            myBoard.loseMoney(myBoard.getTowerClicked()->getPCost());
            myBoard.getTowerClicked()->upgradePower();
        }
        //cerr << "an upgrade has been clicked" << endl;

    }
    //cerr << clickX << " " << clickY << endl;
    //cerr << cellDim*21 << " " << cellDim*(numRows+2) << endl;
        //  The update() function belongs to the QWidget parent class, and instructs the window
	//  that the screen needs to be redrawn.  Leave this at the end of your mousePressEvent function
	update();
}

int MyPaint::onMoveButton(int x, int y) {           // detects if the mouse clicks in the movement box

    //checks to see if mouse press is within bounds of the button
    if(x >= cellDim && x <= 6*cellDim && y>= cellDim*(numRows+2) && y <= cellDim*(numRows+5) ) {
            return 1;
    }

    else{
        return 0;
    }

}

int MyPaint::onBasicTowerButton(int x, int y) {           // detects if the mouse clicks in the movement box

    //checks to see if mouse press is within bounds of the button
    if(x >= 7*cellDim && x <= 9*cellDim && y>= cellDim*(numRows+2) && y <= cellDim*(numRows+4) ) {
        //cerr << "Clicked basic tower button!" << endl;
            return 1;
    }

    else{
        return 0;
    }

}
