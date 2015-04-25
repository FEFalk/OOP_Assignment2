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
	bool GetCollisionStatus(int i);
	
protected: 
	double radius;
	bool collisionStatus[4];
	int statusSize;

};