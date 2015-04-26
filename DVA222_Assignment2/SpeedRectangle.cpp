#include "speedRectangle.h"
#include "Graphix.h"

SpeedRectangle::SpeedRectangle(int x, int y, double width, double height) : Rectangle(x, y, width, height)
{
	newSpeed = 1.03;

}

SpeedRectangle::~SpeedRectangle()
{
}



void SpeedRectangle::Draw()
{
	SetColor(255, 0, 0);
	Rectangle::Draw();
}

float SpeedRectangle::getNewSpeed()
{
	return newSpeed;
}