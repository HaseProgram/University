#include "stdafx.h"
#include "model.h"

Model::Model()
{

}

Model::Model(const Model& model)
{
	this->points = model.points;
	this->edges = model.edges;
};

Model& Model::operator=(const Model& model)
{
	this->points = model.points;
	this->edges = model.edges;

	return *this;
}

Model::~Model()
{
	if (this->pointsCount() != 0)
	{
		this->points.clear();
	}
	if (this->edgesCount() != 0)
	{
		this->edges.clear();
	}
}

Array<Point>& Model::getPoints()
{
	return this->points;
}

Array<Edge>& Model::getEdges()
{
	return this->edges;
}

void Model::addPoint(Point& point)
{
	this->points.addItem(point);
}

void Model::addEdge(Edge& edge)
{
	this->edges.addItem(edge);
}

size_t Model::pointsCount() const
{
	return this->points.count();
}

size_t Model::edgesCount() const
{
	return this->edges.count();
}

void Model::modificate(BaseModification* modification)
{
	for (unsigned int i = 0; i < edges.count(); i++)
	{

	}
}