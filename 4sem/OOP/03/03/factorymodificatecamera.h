#pragma once

/*!
\brief  Returns object of camera movement action
\author Dmitry Zaitsev
\version 1.0
\date 09 June 2016

Factory pattern
*/

#include "factorymodification.h"
#include "modificatecamera.h"

class FactoryModificationCameraPitch : public FactoryModification
{
public:
	FactoryModificationCameraPitch(double angle)
	{
		this->angle = angle;
	}
	~FactoryModificationCameraPitch()
	{
	}

	virtual BaseModification* getModification() override
	{
		return (BaseModificationCamera*) new Pitch(this->angle);
	}

private:
	double angle;
};

class FactoryModificationCameraYaw : public FactoryModification
{
public:
	FactoryModificationCameraYaw(double angle)
	{
		this->angle = angle;
	}
	~FactoryModificationCameraYaw()
	{
	}

	virtual BaseModification* getModification() override
	{
		return  (BaseModificationCamera*) new Yaw(this->angle);
	}

private:
	double angle;
};

class FactoryModificationCameraRoll : public FactoryModification
{
public:
	FactoryModificationCameraRoll(double angle)
	{
		this->angle = angle;
	}
	~FactoryModificationCameraRoll()
	{
	}

	virtual BaseModification* getModification() override
	{
		return  (BaseModificationCamera*) new Roll(this->angle);
	}

private:
	double angle;
};

class FactoryModificateCameraRotateVerticalSphere : public FactoryModification
{
public:
	FactoryModificateCameraRotateVerticalSphere(double angle)
	{
		this->angle = angle;
	}
	~FactoryModificateCameraRotateVerticalSphere()
	{
	}

	virtual BaseModification* getModification() override
	{
		return  (BaseModificationCamera*) new RotateVerticalSphere(this->angle);
	}

private:
	double angle;
};

class FactoryModificateCameraRotateHorizontalSphere : public FactoryModification
{
public:
	FactoryModificateCameraRotateHorizontalSphere(double angle)
	{
		this->angle = angle;
	}
	~FactoryModificateCameraRotateHorizontalSphere()
	{
	}

	virtual BaseModification* getModification() override
	{
		return  (BaseModificationCamera*) new RotateHorizontalSphere(this->angle);
	}

private:
	double angle;
};
