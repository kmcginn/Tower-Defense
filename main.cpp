/*
Project Group: Chris Groce, Kevin McGinn, Nick Taylor
CSE 20212
3/27/2012

main.cpp

This is the driver class for the Tower Defense display
 */
 
 
#include <QApplication>

#include "MyPaint.h"

int main(int argc, char *argv[]) {
     QApplication app(argc, argv); // create a QApplication
     MyPaint p; // create a MyPaint
     p.show(); // run program
     return app.exec();
 }
