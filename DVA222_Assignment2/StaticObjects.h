#pragma once
#include "Shape.h"
#include "Ball.h"

class StaticObjects : public Shape
{
public:
	StaticObjects();
	~StaticObjects();

	virtual bool CollisionCheck(Ball &ball) = 0;


};

