#pragma once
#include "StaticObjects.h"

class Rectangle : public StaticObjects
{
public:
	Rectangle(int x, int y, double width, double height);
	~Rectangle();

	virtual void Draw();
	Size getSize();


protected:
	Size size;
};

