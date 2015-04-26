#include "Rectangle.h"
#include "Graphix.h"

Rectangle::Rectangle(int x, int y, double width, double height)
{
	position.X = x;
	position.Y = y;
	size.Width = width;
	size.Height = height;
}


Rectangle::~Rectangle()
{
}

void Rectangle::Draw()
{
	DrawRectanle((int)position.X, (int)position.Y, (int)size.Width, (int)size.Height);
}


Size Rectangle::getSize()
{
	return size;
}

bool Rectangle::CollisionCheck(Ball &ball)
{
	Vector horizontalCorner;
	Vector verticalCorner;

	horizontalCorner.X = position.X;
	horizontalCorner.Y = position.X + size.Width;

	verticalCorner.X = position.Y;
	verticalCorner.Y = position.Y + size.Height;

	if (ball.GetPosition().X + (ball.GetRadius() / 2) > horizontalCorner.X
		&& ball.GetPosition().X - (ball.GetRadius() / 2) < horizontalCorner.Y
		&& ball.GetPosition().Y + (ball.GetRadius() / 2) > verticalCorner.X
		&& ball.GetPosition().Y - (ball.GetRadius() / 2) < verticalCorner.Y)
	{
		return true;
	}
	else
		return false;
}