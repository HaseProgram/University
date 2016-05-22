#pragma once

/*!
\brief  Model structure
\author Dmitry Zaitsev
\version 1.0
\date 22 May 2016

Contain points and edges structures. File loads in here.
*/

#include "point.h"
#include "edge.h"
#include "array.h"

class ModelBase
{
public:
	ModelBase() {};
	~ModelBase() {};

	virtual void addPoint(Point&) = 0;
	virtual void addEdge(Edge&) = 0;

	virtual size_t pointsCount() const = 0;
	virtual size_t edgesCount() const = 0;

};

class Model : public ModelBase
{
public:
	Model();
	Model(const Model& model) 
	{
		this->points = model.points;
		this->edges = model.edges;
	};

	Model& operator=(const Model& model)
	{
		this->points = model.points;
		this->edges = model.edges;

		return *this;

	}
	~Model();

	IArray<Point>& getPoints();
	IArray<Edge>& getEdges();

	virtual void addPoint(Point&) override;
	virtual void addEdge(Edge&) override;

	virtual size_t pointsCount() const override;
	virtual  size_t edgesCount() const override;


private:
	IArray<Point> points;
	IArray<Edge> edges;
};