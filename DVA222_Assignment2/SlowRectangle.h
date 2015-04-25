#pragma once
#include "Rectangle.h"

class SlowRectangle : public Rectangle
{
public:
	SlowRectangle(int x, int y, double width, double height);
	~SlowRectangle();

	virtual void Draw();
	float getNewSpeed();

private:
	float newSpeed;

};

