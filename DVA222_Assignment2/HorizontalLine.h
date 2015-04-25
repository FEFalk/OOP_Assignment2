#pragma once
#include "Line.h"

class HorizontalLine : public Line
{
public:
	HorizontalLine(int x, int y, int x2, int y2);
	~HorizontalLine();

	virtual void Draw();
};

