#include "SlowRectangle.h"
#include "Graphix.h"

SlowRectangle::SlowRectangle(int x, int y, double width, double height) : Rectangle(x, y, width, height)
{
	newSpeed = 0.99;
}


SlowRectangle::~SlowRectangle()
{
}

void SlowRectangle::Draw()
{
	SetColor(0, 0, 255);
	Rectangle::Draw();
}

float SlowRectangle::getNewSpeed()
{
	return newSpeed;
}