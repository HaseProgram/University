#include "stdafx.h"
#include "drawer.h"
#include "array.h"

Drawer::Drawer(BaseSystemDrawer* systemDrawer)
{
	this->systemDrawer = systemDrawer;
}

Drawer::~Drawer()
{

}

void Drawer::drawmodel(Model* model, Camera* camera)
{
	Camera* cam = camera;
	Array<Edge> edges = model->getEdges();
	if (edges.count() == 0)
	{
		throw DrawerEmptyModelError();
	}

	IArray<Edge> edgesiterator(edges);

	while (edgesiterator.check())
	{
		Edge e = edgesiterator.value();

		Matrix<double> view = camera->getView();
		Vector start(e.getFirstPoint()->vector());
		Vector end(e.getSecondPoint()->vector());

		start = start * view;
		end = end * view;

		this->systemDrawer->drawline(Point(start), Point(end));
		edgesiterator.next();
	}
}