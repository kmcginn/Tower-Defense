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
#include <QtGui>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


// constructor
MyPaint::MyPaint(QWidget *parent)
  : QWidget(parent), myBoard(":/map1.txt") {
     setWindowTitle(tr("Tower Defense"));
     windowHorizontal = 512;
     windowVertical = 512;
     cellDim = windowHorizontal / myBoard.getHoriz();
     numRows = myBoard.getVert();
     numCols = myBoard.getHoriz();
     resize(windowHorizontal, windowVertical);
}

// This method is called when the widget needs to be redrawn.
//
void MyPaint::paintEvent(QPaintEvent *) {


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
                            painter.setBrush(Qt::blue);
                            break;
                        //tile is for enemies
                        case 'P':
                            painter.setBrush(Qt::yellow);
                            break;
                        //tile is for nothing (hole)
                        case 'H':
                            painter.setBrush(Qt::black);
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

            //if enemies are moving, draw them
            if(myBoard.isMoving()){
                int numEnemies = myBoard.enemyListSize();
                Enemy * temp;
                painter.setBrush(Qt::red); //change for different enemy types in final project
                //go through all enemies
                for(int i = 0; i < numEnemies; i++) {
                    temp = myBoard.getEnemy(i);
                    //draw ellipse to represent enemy
                    painter.drawEllipse(cellDim*temp->getPosX() + cellDim/4, cellDim*temp->getPosY() + cellDim/4, cellDim/2, cellDim/2 );
                    //make the enemy move
                    temp->move(myBoard.getGrid());
                }
            }

            //draws the button for making the enemies move
            painter.setBrush(Qt::blue);
            painter.drawRect(cellDim, cellDim*(numRows + 2), 5*cellDim, 3*cellDim);

            sleep(1); //change duration later
            update();

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



    if(onMoveButton(e->x(), e->y())){           // when move button is clicked, the ememy strts moving
            myBoard.startMoving();
    }

    else{
        myBoard.stopMoving();                   // a click anywhere else stops the enemy
    }

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