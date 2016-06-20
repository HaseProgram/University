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
		we have not set_ function with const param 
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
	this->right = right;
}

void Camera::setUp(Array<double> up)
{
	this->up = up;
}

void Camera::setDirection(Array<double> direction)
{
	this->direction = direction;
}

void Camera::setPosition(Array<double> position)
{
	this->position = position;
}

void Camera::setTarget(Array<double> target)
{
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
	Matrix<double> transform = matrixrotation(this->getDirection().getX(), this->getDirection().getY(), this->getDirection().getZ(), angle);
	//this->setUp(this->getUp() * transform);
	//this->setDirection(this->getDirection() * transform);
}

void Camera::rotateHorizontalSphere(double angle)
{
	Matrix<double> transform = matrixrotation(this->getRight().getX(), this->getRight().getY(), this->getRight().getZ(), angle);
	//this->setUp(this->getUp() * transform);
	//this->setDirection(this->getDirection() * transform);
}