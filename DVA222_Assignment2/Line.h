#pragma once
#include "StaticObjects.h"

class Line : public StaticObjects
{
public:
	Line(int x, int y, int x2, int y2);
	~Line();

	virtual void Draw();


protected:
	Vector pos1, pos2;
};

