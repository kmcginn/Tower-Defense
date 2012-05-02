/*
Project Group: Chris Groce, Kevin McGinn, Nick Taylor
CSE 20212

Final Revision: 5/2/2012

MyPaint.h

This is the interface for the MyPaint class, which
acts as a display for the TowerDefense game

MyPaint is based off of the original file by Phil MacCart
 */

#ifndef MYPAINT_H_
#define MYPAINT_H_
 
//!
//! The Q_OBJECT macro tells us that this class can have
//! slots and signals.  It also tells qmake to compile this
//! class in a special way
//!

#include <QWidget>
#include "Board.h"

using namespace std;

//class definition
class MyPaint : public QWidget {
 	Q_OBJECT

public:
	MyPaint(QWidget *parent = 0);

protected:
        void paintEvent(QPaintEvent *e); //puts graphics on the screen
        void mousePressEvent(QMouseEvent *e); //interprets mouse presses

private:
        //data
        Board myBoard; //Board the game is playing on
        int windowHorizontal; //horizontal window size
        int windowVertical; //vertical window size
        int cellDim; //dimension of each cell
        int numRows; //number of rows on screen
        int numCols; //number of cols on screen
        int clock; // background clock for determining timing of attacks and movements

        //helper functions
        int onMoveButton(int, int); //returns whether or not mouse click is within the bounds of the movement button
        int onBasicTowerButton(int, int); //returns whether or not mouse click is within the bounds of the basic tower button
        int onQuickTowerButton(int, int); //returns whether or not mouse click is within the bounds of the quick tower button
        int onFireTowerButton(int, int); //returns whether or not mouse click is within the bounds of the fire tower button
        int onSellButton(int, int); //returns whether or not mouse click is within the bounds of the sell button
        int onUpgradePButton(int, int); //returns whether or not mouse click is within the bounds of the upgrade power button
        int onUpgradeFRButton(int, int); //returns whether or not mouse click is within the bounds of the upgrade firing rate button
        int onUpgradeRButton(int, int); //returns whether or not mouse click is within the bounds of the upgrade range button

        //pixmaps
        QPixmap grassMap;
        QPixmap basicButtonMap;
        QPixmap pathMap;
        QPixmap holeMap;
        QPixmap quickButtonMap;
        QPixmap fireButtonMap;
        QPixmap rangeButtonMap;
        QPixmap firingRateButtonMap;
        QPixmap powerButtonMap;
        QPixmap sellButtonMap;
        QPixmap waveButtonMap;
        //brushes
        QBrush grassBrush;
        QBrush basicButtonBrush;
        QBrush pathBrush;
        QBrush holeBrush;
        QBrush fireButtonBrush;
        QBrush rangeButtonBrush;
        QBrush firingRateButtonBrush;
        QBrush powerButtonBrush;
        QBrush sellButtonBrush;
        QBrush waveButtonBrush;
        QBrush quickButtonBrush;

};

#endif
