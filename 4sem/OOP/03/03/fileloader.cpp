#include "stdafx.h"
#include "fileloader.h"

FLoaderImpl::FLoaderImpl(const char* filename)
{
	this->filename = filename;
	this->file = NULL;
	this->amountPoints = 0;
	this->amountEdges = 0;
}

void FLoaderImpl::openFile()
{
	if ((this->file = fopen(this->filename, "r")) == NULL)
	{
		throw FileLoaderOpenFileError();
	}
}

void FLoaderImpl::closeFile()
{
	fclose(this->file);
}

bool FLoaderImpl::readAmount(unsigned int& amount)
{
	return (fscanf(this->file, "%u", &amount) == 1);
}

Point FLoaderImpl::readPoint()
{
	double x, y, z;
	if (fscanf(this->file, "%lf %lf %lf", &x, &y, &z) != 3)
	{
		throw FileLoaderParametersError();
	}
	Point point;
	point.setX(x);
	point.setY(y);
	point.setZ(z);
	return point;
}

Edge FLoaderImpl::readEdge(Model* model) const
{
	unsigned int p1, p2;
	if (fscanf(this->file, "%u %u", &p1, &p2) != 2)
	{
		throw FileLoaderParametersError();
	}
	Edge edge;
	IArray<Point> pointArrayIterator(model->getPoints());
	if (!pointArrayIterator.getByCount(p1))
	{
		throw IteratorAccessElementError();
	}
	edge.setFirstPoint(&pointArrayIterator.value());
	if(!pointArrayIterator.getByCount(p2))
	{
		throw IteratorAccessElementError();
	}
	edge.setSecondPoint(&pointArrayIterator.value());
	return edge;
}

void FLoaderImpl::readPoints(Model* model)
{
	unsigned int count;
	if (!this->readAmount(count))
	{
		throw FileLoaderParametersError();
	}
	for (unsigned int i = 0; i < count; i++)
	{
		Point point = this->readPoint();
		model->addPoint(point);
	}
}

void FLoaderImpl::readEdges(Model* model)
{
	unsigned int count;
	if (!this->readAmount(count))
	{
		throw FileLoaderParametersError();
	}
	for (unsigned int i = 0; i < count; i++)
	{
		model->addEdge(this->readEdge(model));
	}
}

Model* FLoaderImpl::readModel()
{
	Model* model = new Model;
	if (!model)
	{
		throw AllocationMemoryError();
	}
	try
	{
		this->readPoints(model);
		this->readEdges(model);
	}
	catch (BaseException& err)
	{
		delete model;
		model = nullptr;
		throw;
	}
	return model;
}

BaseSceneElement* FLoaderImpl::loadModel(BaseSceneElement* cobject)
{
	this->openFile();

	unsigned int count;
	if (!this->readAmount(count))
	{
		this->closeFile();
		throw FileLoaderParametersError();
	}

	try
	{
		for (unsigned int i = 0; i < count; i++)
		{
			cobject->add(this->readModel());
		}
		this->closeFile();
		return cobject;
	}
	catch(BaseException& err)
	{
		this->closeFile();
		throw;
	}

	return cobject;
}

BaseSceneElement* FLoader::loadModel(BaseSceneElement* cobject)
{
	return this->blimpl->loadModel(cobject);
}