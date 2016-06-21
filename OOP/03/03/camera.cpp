#include "stdafx.h"
#include "camera.h"

Camera::Camera()
{

}

Camera::Camera(Point* position, Point* target, double pitch, double yaw, double roll)
{
	this->position = position->vector();
	this->target = target->vector();

	/*	
		we have not set_ functions with const param 
		and I don't wanna create them, so... double one = 1; :D
	*/
	double one = 1;

	this->right.setX(one);
	this->right.setL(one);

	this->up.setY(one);
	this->up.setL(one);

	this->direction.setZ(one);
	this->direction.setL(one);

	this->position.setL(one);
	this->target.setL(one);

	this->pitch(pitch);
	this->yaw(yaw);
	this->roll(roll);
}

void Camera::setRight(Array<double> right)
{
	if (right.count() != 4)
	{
		CameraWrongVectorSettingsError();
	}
	this->right = right;
}

void Camera::setUp(Array<double> up)
{
	if (up.count() != 4)
	{
		CameraWrongVectorSettingsError();
	}
	this->up = up;
}

void Camera::setDirection(Array<double> direction)
{
	if (direction.count() != 4)
	{
		CameraWrongVectorSettingsError();
	}
	this->direction = direction;
}

void Camera::setPosition(Array<double> position)
{
	if (position.count() != 4)
	{
		CameraWrongVectorSettingsError();
	}
	this->position = position;
}

void Camera::setTarget(Array<double> target)
{
	if (target.count() != 4)
	{
		CameraWrongVectorSettingsError();
	}
	this->target = target;
}

Vector Camera::getRight()
{
	return this->right;
}

Vector Camera::getUp()
{
	return this->up;
}

Vector Camera::getDirection()
{
	return this->direction;
}

Vector Camera::getPosition()
{
	return this->position;
}

Vector Camera::getTarget()
{
	return this->target;
}

void Camera::modificate(BaseModificationCamera* modification)
{
	modification->run(this);
}

void Camera::pitch(double angle)
{
	Matrix<double> transform = matrixrotation(this->getRight().getX(), this->getRight().getY(), this->getRight().getZ(), angle);
	this->setUp(this->getUp() * transform);
	this->setDirection(this->getDirection() * transform);
}

void Camera::yaw(double angle)
{
	Matrix<double> transform = matrixrotation(this->getUp().getX(), this->getUp().getY(), this->getUp().getZ(), angle);
	this->setRight(this->getRight() * transform);
	this->setDirection(this->getDirection() * transform);
}

void Camera::roll(double angle)
{
	Matrix<double> transform = matrixrotation(this->getDirection().getX(), this->getDirection().getY(), this->getDirection().getZ(), angle);
	this->setRight(this->getRight() * transform);
	this->setUp(this->getUp() * transform);
}

void Camera::rotateVerticalSphere(double angle)
{
	Matrix<double> transform = matrixrotation(this->getUp().getX(), this->getUp().getY(), this->getUp().getZ(), angle);
	this->setUp(this->getUp() * transform);
	this->setDirection(this->getDirection() * transform);
	Matrix<double> move = matrixmove(this->getTarget().getX(), this->getTarget().getY(), this->getTarget().getZ());
	this->setPosition(this->getPosition() * (-move) * transform * move);
}

void Camera::rotateHorizontalSphere(double angle)
{
	Matrix<double> transform = matrixrotation(this->getRight().getX(), this->getRight().getY(), this->getRight().getZ(), angle);
	this->setRight(this->getRight() * transform);
	this->setDirection(this->getDirection() * transform);
	Matrix<double> move = matrixmove(this->getTarget().getX(), this->getTarget().getY(), this->getTarget().getZ());
	this->setPosition(this->getPosition() * (-move) * transform * move);
}

Matrix<double> Camera::getView()
{
	this->direction.normalize();
	
	this->up = Vector::cross(this->direction, this->right);
	this->up.normalize();

	this->right = Vector::cross(this->up, this->direction);
	this->right.normalize();

	double x = -Vector::scalar(this->right, this->position);
	double y = -Vector::scalar(this->up, this->position);
	double z = -Vector::scalar(this->direction, this->position);

	Matrix<double> tmp(4, 4);
	tmp.setColumn(0, this->right.getArray());
	tmp.setColumn(1, this->up.getArray());
	tmp.setColumn(2, this->direction.getArray());

	IArray<double> itmp(tmp[3]);
	itmp[0].updatedir(x);
	itmp[1].updatedir(y);
	itmp[2].updatedir(z);
	itmp[3].updatedir(1);
	return tmp;
}