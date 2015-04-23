#pragma once
#include "Structs.h"

//NOTE:
//----------------------------------------------------------------------
//This is the base class for all drawable objects. You will have to 
//override (redefine) Draw and Update functions in the child classes later
//look how we have done it in the Ball class
//----------------------------------------------------------------------

//NOTICE 2:
//----------------------------------------------------------------------
// DO NOT MODIFY THIS FILE! NEVER EVER! NO EXCUSES ACCEPTED!
// 
// Any violators will be shot! Survivors will be shot again!
//----------------------------------------------------------------------

class Shape
{
public:
	Shape(void);
	~Shape(void);

	virtual void Draw() = 0;
	virtual void Update()
	{}

	Point GetPosition();

protected:
	Point position;
	
};

//---------------------------------------------------------------------
// Did you modify it? Seriously? DON'T!
//---------------------------------------------------------------------
