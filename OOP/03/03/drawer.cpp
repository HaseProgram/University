#include "stdafx.h"
#include "drawer.h"
#include "array.h"

Drawer::Drawer(SystemDrawer* systemDrawer)
{
	this->systemDrawer = systemDrawer;
}

Drawer::~Drawer()
{

}

void Drawer::drawmodel(Model& model, Camera& camera)
{
	Array<Edge> edges = model.getEdges();
	if (edges.count() == 0)
	{
		throw DrawerEmptyModelError();
	}

	IArray<Edge> edgesiterator(edges);

	while (edgesiterator.check())
	{
		Edge e = edgesiterator.value();

		// NEED CAMERA

		this->systemDrawer->drawline(e.getFirstPoint(), e.getSecondPoint());
		edgesiterator.next();
	}
}