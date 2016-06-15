#pragma once

/*!
\brief  Camera modification classes
\author Dmitry Zaitsev
\version 1.0
\date 06 June 2016

Provide camera transformation
*/

#include "basemodificationcamera.h"
#include "camera.h"

class Pitch : public BaseModificationCamera
{
public:
	Pitch(double);

	virtual void run(BaseCamera*) override;

protected:
	double angle;
};

class Yaw : public BaseModificationCamera
{
public:
	Yaw(double);

	virtual void run(BaseCamera*) override;

protected:
	double angle;
};

class Roll : public BaseModificationCamera
{
public:
	Roll(double);

	virtual void run(BaseCamera*) override;

protected:
	double angle;
};
