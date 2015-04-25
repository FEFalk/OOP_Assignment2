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
int lineCount = 4;
Vector newSpeed;

Ball **balls = new Ball*[ballCount];
SpeedRectangle **speedRectangles = new SpeedRectangle*[speedRectangleCount];

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

	speedRectangles[0] = new SpeedRectangle(200, 200, 50, 300);
	speedRectangles[1] = new SpeedRectangle(400, 100, 50, 100);


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
	bool collisionCheck;
	SetColor(255, 255, 255);

	for (int i = 0; i < ballCount; i++)
	{
		for (int j = 0; j < speedRectangleCount; j++)
		{
			collisionCheck=speedRectangles[j]->CollisionCheck(*balls[i]);
			if (collisionCheck)
				balls[i]->SetSpeed(Vector(speedRectangles[j]->getNewSpeed()*balls[i]->GetSpeed().X, speedRectangles[j]->getNewSpeed()*balls[i]->GetSpeed().Y));
		}
		balls[i]->Update();
		balls[i]->Draw();
	}

	for (int i = 0; i < speedRectangleCount; i++)
	{
		speedRectangles[i]->Draw();
	}

	for (int i = 0; i < lineCount; i++)
	{
		lines[i]->Draw();
	}


	Redraw();
}