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

	void onCollisionEnter(Ball &ball);

protected:
	Size size;

};

