#include "stdafx.h"
#include "fileloader.h"

FLoader::FLoader(const char* filename)
{
	this->filename = filename;
	this->file = NULL;
	this->amountPoints = 0;
	this->amountEdges = 0;
}

void FLoader::openFile()
{
	if ((this->file = fopen(this->filename, "r")) == NULL)
	{
		throw FileLoaderOpenFileError();
	}
}

void FLoader::closeFile()
{
	fclose(this->file);
}

bool FLoader::readAmount(unsigned int& amount)
{
	return (fscanf(this->file, "%u", &amount) == 1);
}

Point FLoader::readPoint()
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

Edge FLoader::readEdge(Model* model) const
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

void FLoader::readPoints(Model* model)
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

void FLoader::readEdges(Model* model)
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

Model* FLoader::readModel()
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

BaseObject* FLoader::loadModel(BaseObject* cobject)
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
