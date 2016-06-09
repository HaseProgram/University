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

