#include "Ball.h"
#include "Graphix.h"


//Constructor
Ball::Ball(int x, int y, int r)
{
	position.X = x;
	position.Y = y;
	radius = r;
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
