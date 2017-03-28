#pragma once

/*!
\brief  Model structure
\author Dmitry Zaitsev
\version 3.0
\date 22 May 2016

Contain points and edges structures. File loads in here.
*/

#include "point.h"
#include "edge.h"
#include "array.h"

class BaseModel : public BaseObject
{
public:
	virtual void addPoint(Point&) = 0;
	virtual void addEdge(Edge&) = 0;

	virtual size_t pointsCount() const = 0;
	virtual size_t edgesCount() const = 0;

	virtual void modificate(BaseModificationObject*) = 0;
};

class Model : public BaseModel
{
public:
	Model();
	Model(const Model& model);

	Model& operator=(const Model& model);
	~Model();

	Array<Point>& getPoints();
	Array<Edge>& getEdges();

	virtual void addPoint(Point&) override;
	virtual void addEdge(Edge&) override;

	virtual size_t pointsCount() const override;
	virtual  size_t edgesCount() const override;

	virtual void modificate(BaseModificationObject*) override;

private:
	Array<Point> points;
	Array<Edge> edges;
};