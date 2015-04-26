#include "HorizontalLine.h"
#include "Graphix.h"

HorizontalLine::HorizontalLine(int x, int y, int x2, int y2) : Line(x, y, x2, y2)
{
	size.Height = 5;
	size.Width = 0;
}
HorizontalLine::~HorizontalLine()
{
}

void HorizontalLine::Draw()
{
	SetColor(0, 255, 0);
	Line::Draw();
}