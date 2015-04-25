#include "HorizontalLine.h"
#include "Graphix.h"

HorizontalLine::HorizontalLine(int x, int y, int x2, int y2) : Line(x, y, x2, y2)
{

}
HorizontalLine::~HorizontalLine()
{
}

void HorizontalLine::Draw()
{
	SetColor(0, 255, 0);
	Line::Draw();
}