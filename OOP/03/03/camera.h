#pragma once

/*!
\brief  Camera structure
\author Dmitry Zaitsev
\version 1.0
\date 08 June 2016

Viewer. Drawing model will depends on camera state.
*/

#include "point.h"
#include "vector.h"
#include "basecamera.h"
class Camera : public BaseCamera
{
public:
	Camera();
	Camera(Point&, Point&, double, double, double);

	void setRight(Array<double>);
	void setUp(Array<double>);
	void setDirection(Array<double>);

	void setPosition(Array<double>);
	void setTarget(Array<double>);

	Vector getRight();
	Vector getUp();
	Vector getDirection();

	Vector getPosition();
	Vector getTarget();

	virtual void modificate(BaseModificationCamera*) override;

	virtual void pitch(double) override;
	virtual void yaw(double) override;
	virtual void roll(double) override;

	virtual void rotateVerticalSphere(double) override;
	virtual void rotateHorizontalSphere(double) override;
private:
	Vector right;
	Vector up;
	Vector direction;

	Vector position;
	Vector target;
};