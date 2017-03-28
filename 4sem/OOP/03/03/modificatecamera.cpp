#include "stdafx.h"
#include "modificatecamera.h"

Pitch::Pitch(double angle)
{
	this->angle = angle;
}

void Pitch::run(BaseCamera* camera)
{
	camera->pitch(this->angle);
}

Yaw::Yaw(double angle)
{
	this->angle = angle;
}

void Yaw::run(BaseCamera* camera)
{
	camera->yaw(this->angle);
}

Roll::Roll(double angle)
{
	this->angle = angle;
}

void Roll::run(BaseCamera* camera)
{
	camera->roll(this->angle);
}

RotateVerticalSphere::RotateVerticalSphere(double angle)
{
	this->angle = angle;
}

void RotateVerticalSphere::run(BaseCamera* camera)
{
	camera->rotateVerticalSphere(this->angle);
}

RotateHorizontalSphere::RotateHorizontalSphere(double angle)
{
	this->angle = angle;
}

void RotateHorizontalSphere::run(BaseCamera* camera)
{
	camera->rotateHorizontalSphere(this->angle);
}