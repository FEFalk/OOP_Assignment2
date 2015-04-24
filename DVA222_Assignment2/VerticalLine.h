#pragma once
#include "Line.h"

class VerticalLine : Line
{
public:
	VerticalLine(int x, int y, int x2, int y2) : Line(x, y, x2, y2){};
	~VerticalLine();
};

