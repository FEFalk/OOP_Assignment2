#pragma once
#include "StaticObjects.h"

class Line : public StaticObjects
{
public:
	Line(int x, int y, int x2, int y2);
	~Line();

	virtual void Draw();

	bool Line::CollisionCheck(Ball &ball);


protected:
	Vector pos1, pos2;
};

