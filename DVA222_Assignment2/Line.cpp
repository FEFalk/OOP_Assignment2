#include "Line.h"
#include "Graphix.h"


Line::Line(int x, int y, int x2, int y2)
{
	pos1.X = x;
	pos1.Y = y;
	pos2.X = x2;
	pos2.Y = y2;
}


Line::~Line()
{
}

void Line::Draw()
{
	DrawLine(pos1.X, pos1.Y, pos2.X, pos2.Y);
}
bool Line::CollisionCheck(Ball &ball)
{
	bool collisionCheck = false;

	Vector startingPoint;
	Vector endingPoint;

	startingPoint.X = pos1.X;
	startingPoint.Y = pos1.Y;
	endingPoint.X = pos2.X;
	endingPoint.Y = pos2.Y;


	if ((ball.GetPosition().X + (ball.GetRadius() / 2) > startingPoint.X
		&& ball.GetPosition().X - (ball.GetRadius() / 2) < endingPoint.X
		&& ball.GetPosition().Y + (ball.GetRadius() / 2) == endingPoint.Y)
		|| (ball.GetPosition().Y - (ball.GetRadius() / 2) > startingPoint.Y
		&& ball.GetPosition().Y + (ball.GetRadius() / 2) < endingPoint.Y
		&& ball.GetPosition().X + (ball.GetRadius() / 2) == endingPoint.X))
	{
		return true;
	}
	else
	{
		return false;
	}
	
}