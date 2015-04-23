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
	DrawRectanle(position.X, position.Y, (int)size.Width, (int)size.Height);
}


Size Rectangle::getSize()
{
	return size;
}
