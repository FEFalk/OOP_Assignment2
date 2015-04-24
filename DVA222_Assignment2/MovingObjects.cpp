#include "MovingObjects.h"


MovingObjects::MovingObjects()
{
}


MovingObjects::~MovingObjects()
{
}


//Overrided Update function, it is responsible for updating the object's location for each frame of the animation
void MovingObjects::Update()
{
	position.X += speed.X;
	position.Y += speed.Y;
	
}



void MovingObjects::SetSpeed(Vector newSpeed)
{
	speed = newSpeed;
}

Vector MovingObjects::GetSpeed()
{
	return speed;
}