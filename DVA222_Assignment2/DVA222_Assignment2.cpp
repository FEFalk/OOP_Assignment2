// DVA222_Assignment2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <math.h>
#include <time.h> 
#include "Graphix.h"

#include "Ball.h"
#include "SpeedRectangle.h"
#include "SlowRectangle.h"
#include "VerticalLine.h"
#include "HorizontalLine.h"

int ballCount = 20;
int speedRectangleCount = 2;
int slowRectangleCount = 2;

int verticalLineCount = 2;
int horizontalLineCount = 2;


Ball **balls = new Ball*[ballCount];
SpeedRectangle **speedRectangles = new SpeedRectangle*[speedRectangleCount];
SlowRectangle **slowRectangles = new SlowRectangle*[slowRectangleCount];

VerticalLine **verticalLines = new VerticalLine*[verticalLineCount];
HorizontalLine **horizontalLines = new HorizontalLine*[horizontalLineCount];

		 
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

	speedRectangles[0] = new SpeedRectangle(150, 150, 100, 75);
	speedRectangles[1] = new SpeedRectangle(550, 400, 100, 75);

	slowRectangles[0] = new SlowRectangle(150, 400, 100, 75);
	slowRectangles[1] = new SlowRectangle(550, 150, 100, 75);

	verticalLines[0] = new VerticalLine(50, 50, 50, 550);
	verticalLines[1] = new VerticalLine(750, 50, 750, 550);

	horizontalLines[0] = new HorizontalLine(50, 50, 750, 50);
	horizontalLines[1] = new HorizontalLine(50, 550, 750, 550);

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
			collisionCheck = speedRectangles[j]->CollisionCheck(*balls[i]);
			if (collisionCheck == true){
				balls[i]->SetSpeed(Vector(speedRectangles[j]->getNewSpeed()*balls[i]->GetSpeed().X, speedRectangles[j]->getNewSpeed()*balls[i]->GetSpeed().Y));
		}
		}
		for (int j = 0; j < slowRectangleCount; j++)
		{
			collisionCheck = slowRectangles[j]->CollisionCheck(*balls[i]);
			if (collisionCheck == true){
				balls[i]->SetSpeed(Vector(slowRectangles[j]->getNewSpeed()*balls[i]->GetSpeed().X, slowRectangles[j]->getNewSpeed()*balls[i]->GetSpeed().Y));
			}
		}
		for (int j = 0; j < verticalLineCount; j++)
		{
			collisionCheck = verticalLines[j]->CollisionCheck(*balls[i]);
			if (collisionCheck == true)
				balls[i]->SetSpeed(Vector(balls[i]->GetSpeed().X*-1, balls[i]->GetSpeed().Y));
		}
		for (int j = 0; j < horizontalLineCount; j++)
		{
			collisionCheck = horizontalLines[j]->CollisionCheck(*balls[i]);
			if (collisionCheck == true)
				balls[i]->SetSpeed(Vector(balls[i]->GetSpeed().X, balls[i]->GetSpeed().Y*-1));
		}
		balls[i]->Update();
		balls[i]->Draw();
	}

	for (int i = 0; i < speedRectangleCount; i++)
	{
		speedRectangles[i]->Draw();
	}

	for (int i = 0; i < slowRectangleCount; i++)
	{
		slowRectangles[i]->Draw();
	}
	for (int i = 0; i < verticalLineCount; i++)
	{
		verticalLines[i]->Draw();
	}
	for (int i = 0; i < horizontalLineCount; i++)
	{
		horizontalLines[i]->Draw();
	}

	Redraw();
}