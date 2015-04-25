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