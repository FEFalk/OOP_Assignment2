#pragma once
#include "Line.h"

class VerticalLine : public Line
{
public:
	VerticalLine(int x, int y, int x2, int y2);
	~VerticalLine();

	virtual void Draw();
	float getNewSpeed();
protected:

	float newSpeed;
};

