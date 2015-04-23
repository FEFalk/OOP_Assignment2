//----------------------------------------------------------------------
//These are some basic structures that we use in the code to make it more
//readable and organized. I think you do not have to do anything here apart
//from reading it and learning from the Masters :)
//----------------------------------------------------------------------

//NOTICE 2:
//----------------------------------------------------------------------
// DO NOT MODIFY THIS FILE! NEVER EVER! NO EXCUSES ACCEPTED!
// 
// Any violators will be shot! Survivors will be shot again!
//----------------------------------------------------------------------
typedef struct _point
{
	_point()
	{
	}
	_point(double x, double y)
	{
	 X = x;
	 Y = y;
	}
	double X;
	double Y;
}Point;

typedef struct _size
{
	double Width;
	double Height;
}Size;

typedef _point Vector;



