#include "speedRectangle.h"
#include "Graphix.h"



SpeedRectangle::~SpeedRectangle()
{
}



void SpeedRectangle::Draw()
{
	SetColor(255, 0, 0);
	Rectangle::Draw();
}