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
#include "Rectangle.h"
#include "Line.h"
#include "VerticalLine.h"
#include "HorizontalLine.h"

int ballCount = 20;
int speedRectangleCount = 2;
int slowRectangleCount = 2;
int lineCount = 4;
int verticalLineCount = 4;
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

	speedRectangles[0] = new SpeedRectangle(200, 200, 50, 300);
	speedRectangles[1] = new SpeedRectangle(400, 100, 50, 100);

	slowRectangles[0] = new SlowRectangle(300, 200, 50, 300);
	slowRectangles[1] = new SlowRectangle(100, 100, 50, 100);

	for (int i = 0; i < verticalLineCount; i++)
	{
		verticalLines[i] = new VerticalLine(500, 200, 500, 400);
	}
	verticalLines[0] = new VerticalLine(100, 200, 100, 400);
	verticalLines[1] = new VerticalLine(300, 200, 300, 400);
	verticalLines[2] = new VerticalLine(500, 200, 500, 400);
	verticalLines[3] = new VerticalLine(700, 200, 700, 400);

	for (int i = 0; i < horizontalLineCount; i++)
	{
		horizontalLines[i] = new HorizontalLine(500, 200, 500, 400);
	}
	horizontalLines[0] = new HorizontalLine(200, 50, 600, 50);
	horizontalLines[1] = new HorizontalLine(200, 550, 600, 550);

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
	bool collisionCheck, verticalLineCollisionCheck, horizontalLineCollisionCheck;
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
			verticalLineCollisionCheck = verticalLines[j]->CollisionCheck(*balls[i]);
			if (verticalLineCollisionCheck)
				balls[i]->SetSpeed(Vector(balls[i]->GetSpeed().X*-1, balls[i]->GetSpeed().Y));
		}
		for (int j = 0; j < horizontalLineCount; j++)
		{
			horizontalLineCollisionCheck = horizontalLines[j]->CollisionCheck(*balls[i]);
			if (horizontalLineCollisionCheck)
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
	for (int i = 0; i < verticalLineCount; i++)
	{
		verticalLines[i]->Draw();
	}
	for (int i = 0; i < horizontalLineCount; i++)
	{
		slowRectangles[i]->Draw();
		horizontalLines[i]->Draw();
	}

	Redraw();
}