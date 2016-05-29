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

IArray<Point>& Model::getPoints()
{
	return this->points;
}

IArray<Edge>& Model::getEdges()
{
	return this->edges;
}

void Model::addPoint(Point& point)
{
	this->points.add(point);
}

void Model::addEdge(Edge& edge)
{
	this->edges.add(edge);
}

size_t Model::pointsCount() const
{
	return this->points.count();
}

size_t Model::edgesCount() const
{
	return this->edges.count();
}

void Model::modificate()
{

}