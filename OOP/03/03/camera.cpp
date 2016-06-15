#include "stdafx.h"
#include "camera.h"

Camera::Camera()
{

}

Camera::Camera(Point& position, Point& target, double pitch, double yaw, double roll)
{
	this->position = position.vector();
	this->target = target.vector();

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

void Camera::modificate(BaseModificationCamera* modification)
{
	modification->run(this);
}