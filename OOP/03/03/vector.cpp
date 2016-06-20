#include "stdafx.h"
#include "vector.h"

Vector::Vector()
{
	double t = 0;
	this->v.addItem(t);
	this->v.addItem(t);
	this->v.addItem(t);
	this->v.addItem(t);
}

Vector::Vector(const Vector& cvector)
{
	double t = 0;
	double x = cvector.getX();
	double y = cvector.getY();
	double z = cvector.getZ();
	double l = cvector.getL();
	this->v.addItem(x);
	this->v.addItem(y);
	this->v.addItem(z);
	this->v.addItem(l);
}

Vector::Vector(Array<double> arr)
{
	if (arr.count() != 4)
	{
		//throw VectorSourceSizeError(); // Need add exception file with thouse errors
	}
	IArray<double> iarr(arr);
	while (iarr.check())
	{
		this->v.addItem(iarr.value());
	}
}

Vector::Vector(double x, double y, double z)
{
	this->v.addItem(x);
	this->v.addItem(y);
	this->v.addItem(z);
	double l = 1;
	this->v.addItem(l);
}

Vector::~Vector()
{
	this->v.clear();
}

Array<double>& Vector::getArray()
{
	Array<double> tmp;
	double x = this->getX();
	double y = this->getY();
	double z = this->getZ();
	double l = this->getL();
	tmp.addItem(x);
	tmp.addItem(y);
	tmp.addItem(z);
	tmp.addItem(l);
	return tmp;
}

void Vector::setX(double X)
{
	IArray<double> viterator(this->v);
	viterator.getByCount(0);
	viterator.update(X);
}

void Vector::setY(double Y)
{
	IArray<double> viterator(this->v);
	viterator.getByCount(1);
	viterator.update(Y);
}

void Vector::setZ(double Z)
{
	IArray<double> viterator(this->v);
	viterator.getByCount(2);
	viterator.update(Z);
}

void Vector::setL(double L)
{
	IArray<double> viterator(this->v);
	viterator.getByCount(3);
	viterator.update(L);
}

double Vector::getX() const
{
	IArrayConst<double> viterator(this->v);
	viterator.getByCount(0);
	return viterator.value();
}

double Vector::getY() const
{
	IArrayConst<double> viterator(this->v);
	viterator.getByCount(1);
	return viterator.value();
}

double Vector::getZ() const
{
	IArrayConst<double> viterator(this->v);
	viterator.getByCount(2);
	return viterator.value();
}

double Vector::getL() const 
{
	IArrayConst<double> viterator(this->v);
	viterator.getByCount(3);
	return viterator.value();
}

double Vector::operator[](int index)
{
	IArrayConst<double> viterator(this->v);
	viterator.getByCount(index);
	return viterator.value();
}

double Vector::length()
{
	if (this->v.count() != 4)
	{
		throw VectorSizeError();
	}
	IArray<double> viterator(this->v);
	double x = viterator.getByCount(0);
	double y = viterator.getByCount(1);
	double z = viterator.getByCount(2);

	return sqrt(x*x + y*y + z*z);
}

double Vector::scalar(Vector vec1, Vector vec2)
{
	if (vec1.v.count() != 4 || vec2.v.count() != 4)
		throw VectorSizeError();

	IArray<double> viterator1(vec1.v);
	IArray<double> viterator2(vec2.v);
	return	viterator1.getByCount(0) * viterator2.getByCount(0)  + 
			viterator1.getByCount(1) * viterator2.getByCount(1) +
			viterator1.getByCount(2) * viterator2.getByCount(2);
}


double Vector::angle(Vector vec1, Vector vec2)
{
	if (vec1.v.count() != 4 || vec2.v.count() != 4)
		throw VectorSizeError();
	return scalar(vec1, vec2) / (vec1.length() * vec2.length());
}

Vector Vector::normalize()
{
	if ((*this).v.count() != 4)
		throw VectorSizeError();

	double norm = 1 / (*this).length();

	IArray<double> viterator(this->v);
	while (viterator.check())
	{
		double nv = viterator.value() * norm;
		viterator.update(nv);
		viterator.next();
	}

	return (*this);
}

Vector Vector::cross(Vector vec1, Vector vec2)
{
	Vector tmp;
	tmp.setX(vec1.getZ() * vec2.getY() - vec1.getY() * vec2.getZ());
	tmp.setY(vec1.getX() * vec2.getZ() - vec1.getZ() * vec2.getX());
	tmp.setZ(vec1.getY() * vec2.getX() - vec1.getX() * vec2.getY());
	return tmp;
}

Vector& Vector::operator=(Array<double>& other)
{
	if (other.count() != 4)
		throw VectorSizeError();

	IArray<double> viterator1(this->v);
	IArray<double> viterator2(other);
	while (viterator2.check())
	{
		viterator1.update(viterator2.value());
		viterator1.next();
		viterator2.next();
	}

	return (*this);
}

Vector &Vector::operator=(Array<double>&& other)
{
	if (other.count() != 4)
		throw VectorSizeError();

	IArray<double> viterator1(this->v);
	IArray<double> viterator2(other);
	while (viterator2.check())
	{
		viterator1.update(viterator2.value());
		viterator1.next();
		viterator2.next();
	}

	return (*this);
}