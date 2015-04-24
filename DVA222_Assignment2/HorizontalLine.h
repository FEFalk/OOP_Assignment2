#pragma once
#include "Line.h"

class HorizontalLine : Line 
{
public:
	HorizontalLine(int x, int y, int x2, int y2) : Line(x, y, x2, y2){};
	~HorizontalLine();
};

