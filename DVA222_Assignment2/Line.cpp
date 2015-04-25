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

	Vector horizontalCorner;
	Vector verticalCorner;

	horizontalCorner.X = GetPosition().X;
	horizontalCorner.Y = GetPosition().X + getSize().Width;

	verticalCorner.X = GetPosition().Y;
	verticalCorner.Y = GetPosition().Y + getSize().Height;

	if (ball.GetPosition().X + (ball.GetRadius() / 2) > horizontalCorner.X
		&& ball.GetPosition().X - (ball.GetRadius() / 2) < horizontalCorner.Y
		&& ball.GetPosition().Y + (ball.GetRadius() / 2) > verticalCorner.X
		&& ball.GetPosition().Y - (ball.GetRadius() / 2) < verticalCorner.Y)
	{
		return true;
	}
	return false;
}