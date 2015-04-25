#include "Ball.h"
#include "Graphix.h"


//Constructor
Ball::Ball(int x, int y, int r)
{
	position.X = x;
	position.Y = y;
	radius = r;
	statusSize = 4;
	for (int i = 0; i < statusSize; i++)
	{
		collisionStatus[i] = false;
	}
}

//Destructor
Ball::~Ball(void)
{
}

//Overrided Draw function
void Ball::Draw()
{
	SetColor(0,255,0);
	DrawCircle(position.X,position.Y, radius);
}

//Some simple Get Set functions
double Ball::GetRadius()
{
	return radius;
}

bool Ball::GetCollisionStatus(int i)
{
	if (i < statusSize && i >= 0)
		return collisionStatus[i];
	else
		return 0;
}