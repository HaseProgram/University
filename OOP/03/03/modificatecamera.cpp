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