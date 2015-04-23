#pragma once
#include "Shape.h"
class MovingObjects : public Shape
{
public:
	MovingObjects();
	~MovingObjects();

	virtual void Update();

	void SetSpeed(Vector newSpeed);
	Vector GetSpeed();


private:
	Vector speed;		//speed is a vector. This means that we have 2 values for the ball's movement along x and y axis separately.
						//This makes it easy to make changes in the direction with relation to any of the x or y axis. For example
						//bouncing back from a vertical border means just reversing the speed in x direction but not y (Why?).


};