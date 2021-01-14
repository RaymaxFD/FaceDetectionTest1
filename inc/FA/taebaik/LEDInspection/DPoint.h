

#pragma once

class DPoint
{
public: 
	double x;
	double y;

public: 
	DPoint()
	{
		x = 0.0;
		y = 0.0;
	}

	DPoint(POINT Point)
	{
		x = Point.x;	  y = Point.y;
	}

	DPoint(double dx,double dy)
	{
		x = dx;	  y = dy;
	}

	virtual ~DPoint(void)
	{
	}

	void Reset()	{ x = 0;	y = 0;}

	void Set(double dX, double dY)
	{
		x=dX;	y=dY;
	}
	void SetDouble(double dX, double dY)
	{
		x=x*dX;	y=x*dY;
	}

	void SetDivide(double dX, double dY)
	{
		if(dX>0)	x=x/dX;	
		if(dY>0)	y=x/dY;
	}

	//Operator Overloading
	DPoint operator+(DPoint Point)
	{
		x = x + Point.x;
		y = y + Point.y;
		return *this;
	}

	DPoint operator-(DPoint Point)
	{
		x = x - Point.x;
		y = y - Point.y;
		return *this;
	}

	DPoint operator=(DPoint Point)
	{
		x = Point.x;
		y = Point.y;
		return *this;
	}

	DPoint operator+=(DPoint Point)
	{
		x += Point.x;
		y += Point.y;
		return *this;
	}

	DPoint operator-=(DPoint Point)
	{
		x -= Point.x;
		y -= Point.y;
		return *this;
	}

	bool operator==(DPoint Point)
	{
		if(x == Point.x && y == Point.y)	return true;
		return false;
	}

	bool operator!=(DPoint Point)
	{
		if(x == Point.x && y == Point.y)	return false;
		return true;
	}

	bool operator>(DPoint Point)
	{
		if(x < Point.x && y < Point.y)	return true;
		return false;
	}

	bool operator<(DPoint Point)
	{
		if(x > Point.x && y > Point.y)	return true;
		return false;
	}

	bool operator>=(DPoint Point)
	{
		if(x <= Point.x && y <= Point.y)	return true;
		return false;
	}

	bool operator<=(DPoint Point)
	{
		if(x >= Point.x && y >= Point.y)	return true;
		return false;
	}
};