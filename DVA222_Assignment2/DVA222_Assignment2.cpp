// DVA222_Assignment2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <math.h>
#include <time.h> 
#include "Graphix.h"

#include "Ball.h"
#include "SpeedRectangle.h"
#include "Rectangle.h"
#include "Line.h"

int ballCount = 20;
int speedRectangleCount = 2;

Ball **balls = new Ball*[ballCount];
SpeedRectangle **speedRectangles = new SpeedRectangle*[speedRectangleCount];
Rectangle **rectangles = new Rectangle*[redRectangleCount];
Line **lines = new Line*[lineCount];

		 
int _tmain(int argc, char** argv)
{
	//NOTE:
	//----------------------------------------------------------------------
	//Create your objects in the global namespace
	//Initialize your object here, like what we do for the balls
	//----------------------------------------------------------------------
	srand(time(0));
	for(int i = 0; i < ballCount; i++)
	{
		balls[i] = new Ball(400, 300, 10);
		balls[i]->SetSpeed(Vector(10 * rand() / RAND_MAX -5 , 10 * rand() / RAND_MAX -5));
	}

	speedRectangles[0] = new SpeedRectangle(200, 400, 100, 50);
	speedRectangles[1] = new SpeedRectangle(400, 200, 50, 100);
	for (int i = 0; i < redRectangleCount; i++)
	{
		rectangles[i] = new Rectangle(rand()%300, rand()%400, 10, 20);
	}
	for (int i = 0; i < lineCount; i++)
	{
		lines[i] = new Line(20, 20, 200, 20);
	}

	//NOTE:
	//----------------------------------------------------------------------
	//Below this line control of your main is passed to graphix library
	//Don't touch this line, Don't write anything after it
	//Simply just don't do anything after this point ==> . 
	//----------------------------------------------------------------------
    InitGraphix(argc, argv);
    return 0;
}


//NOTE:
//------------------------------------------------------------------------------
//This is the function which is called by the graphix library to draw the objects
//Write all your drawing code here and not in main. 
//If you want to ReDraw stuff, call the ReDraw function at the end.
////------------------------------------------------------------------------------
void Draw()
{
	SetColor(255, 255, 255);

	for (int i = 0; i < ballCount; i++)
	{
		balls[i]->Update();
		balls[i]->Draw();

	}

	for (int i = 0; i < speedRectangleCount; i++)
	{
		speedRectangles[i]->Draw();
		for (int j = 0; j < ballCount; j++)
	{
			speedRectangles[i]->onCollisionEnter(*balls[j]);
		}
	}

	for (int i = 0; i < lineCount; i++)
	{
		lines[i]->Draw();
	}


	Redraw();
}