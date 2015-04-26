#pragma once
#include "MovingObjects.h"
#include "StaticObjects.h"

class Ball : public MovingObjects
{
public:
	Ball(int x, int y, int r);
	~Ball(void);

	virtual void Draw();
	double GetRadius();
	
protected: 
	double radius;

};