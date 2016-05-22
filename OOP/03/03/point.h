#pragma once

/*!
\brief  Point object
\author Dmitry Zaitsev
\version 1.0
\date 21 May 2016

Set point using this class
*/

class PointBase
{
public:
	PointBase() {};
	~PointBase() {};

	virtual void setX(double) = 0;
	virtual void setY(double) = 0;
	virtual void setZ(double) = 0;

	virtual double getX() = 0;
	virtual double getY() = 0;
	virtual double getZ() = 0;
};

class Point : public PointBase
{
public:
	Point(double X, double Y, double Z)
	{
		this->X = X;
		this->Y = Y;
		this->Z = Z;
	}

	~Point()
	{
		this->X = 0;
		this->Y = 0;
		this->Z = 0;
	}

	virtual void setX(double newX)
	{
		this->X = newX;
	}

	virtual void setY(double newY)
	{
		this->Y = newY;
	}

	virtual void setZ(double newZ)
	{
		this->Z = newZ;
	}

	virtual double getX()
	{
		return this->X;
	}

	virtual double getY()
	{
		return this->Y;
	}

	virtual double getZ()
	{
		return this->Z;
	}

private:
	double X;
	double Y;
	double Z;
};