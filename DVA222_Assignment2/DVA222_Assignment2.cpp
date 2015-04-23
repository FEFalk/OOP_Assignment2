// DVA222_Assignment2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <math.h>
#include <time.h> 
#include "Graphix.h"

#include "Ball.h"


int ballCount = 10;

Ball **balls = new Ball*[ballCount];


		 
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


	Redraw();
}