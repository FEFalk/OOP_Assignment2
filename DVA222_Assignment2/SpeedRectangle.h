#pragma once
#include "Rectangle.h"

class SpeedRectangle: public Rectangle
{
public:
	SpeedRectangle(int x, int y, double width, double height);
	~SpeedRectangle();
	
	virtual void Draw();
	float getNewSpeed();
private:

	float newSpeed;

};

