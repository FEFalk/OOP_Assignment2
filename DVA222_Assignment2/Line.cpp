#include "Line.h"
#include "Graphix.h"


Line::Line(int x, int y, int x2, int y2)
{
	pos1.X = x;
	pos1.Y = y;
	pos2.X = x2;
	pos2.Y = y2;
}


Line::~Line()
{
}

void Line::Draw()
{
	DrawLine(pos1.X, pos1.Y, pos2.X, pos2.Y);
}