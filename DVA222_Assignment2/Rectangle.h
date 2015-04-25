#pragma once
#include "StaticObjects.h"
#include "Ball.h"
class Rectangle : public StaticObjects
{
public:
	Rectangle(int x, int y, double width, double height);
	~Rectangle();

	virtual void Draw();
	Size getSize();

	bool CollisionCheck(Ball &ball);

protected:
	Size size;

};

