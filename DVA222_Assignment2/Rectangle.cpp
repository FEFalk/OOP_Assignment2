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

void Rectangle::onCollisionEnter(Ball &ball)
{
	bool collisionCheck = false;

	Vector horizontalCorner;
	Vector verticalCorner;
	Vector newSpeed;
	newSpeed.X = ball.GetSpeed().X + 10;
	newSpeed.Y = ball.GetSpeed().Y + 10;

	horizontalCorner.X = GetPosition().X - getSize().Width / 2;
	horizontalCorner.Y = GetPosition().X + getSize().Width / 2;

	verticalCorner.X = GetPosition().Y - getSize().Height / 2;
	verticalCorner.Y = GetPosition().Y + getSize().Height / 2;

	if (ball.GetPosition().X + ball.GetRadius() / 2 > horizontalCorner.X
		&& ball.GetPosition().X - ball.GetRadius() / 2 < horizontalCorner.Y
		&& ball.GetPosition().Y + ball.GetRadius() / 2 > verticalCorner.X
		&& ball.GetPosition().Y - ball.GetRadius() / 2 < verticalCorner.Y)
	{
		collisionCheck = true;
		ball.SetSpeed(newSpeed);
	}
}