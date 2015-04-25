#include "VerticalLine.h"
#include "Graphix.h"

VerticalLine::VerticalLine(int x, int y, int x2, int y2) : Line(x, y, x2, y2)
{

}

VerticalLine::~VerticalLine()
{
}



void VerticalLine::Draw()
{
	SetColor(255, 255, 0);
	Line::Draw();
}

float VerticalLine::getNewSpeed()
{
	return newSpeed;
}