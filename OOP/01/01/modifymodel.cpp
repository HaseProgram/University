#include "stdafx.h"
#include "modifymodel.h"
#include "model.h"

void modify_model(struct view* View)
{
	switch (View->Modification.type)
	{
	case ROTATE_XZ:
		rot_xz(View);
		break;
	case ROTATE_XY:
		rot_xy(View);
		break;
	case ZOOM:
		zoom(View);
		break;
	}
}

void rot_xz(struct view* View)
{
	double teta = (View->Modification.param) / 180.0 * M_PI;
	double newX, newZ;

	for (int i = 0; i < View->Model.Node.Number; i++)
	{
		newX = ((View->Model.Node.Items + i)->X) * cos(teta) + ((View->Model.Node.Items + i)->Z) * sin(teta);
		newZ = ((View->Model.Node.Items + i)->Z) * cos(teta) - ((View->Model.Node.Items + i)->X) * sin(teta);
		(View->Model.Node.Items + i)->X = newX;
		(View->Model.Node.Items + i)->Z = newZ;
	}
}

void rot_xy(struct view* View)
{
	double teta = (View->Modification.param) / 180.0 * M_PI;
	double newX, newY;

	for (int i = 0; i < View->Model.Node.Number; i++)
	{

		newX = ((View->Model.Node.Items + i)->X) * cos(teta) + ((View->Model.Node.Items + i)->Y) * sin(teta);
		newY = ((View->Model.Node.Items + i)->Y) * cos(teta) - ((View->Model.Node.Items + i)->X) * sin(teta);
		(View->Model.Node.Items + i)->X = newX;
		(View->Model.Node.Items + i)->Y = newY;
	}
}

void zoom(struct view* View)
{
	double k = View->Modification.param;
	for (int i = 0; i < View->Model.Node.Number; i++)
	{
		(View->Model.Node.Items + i)->X *= k;
		(View->Model.Node.Items + i)->Y *= k;
		(View->Model.Node.Items + i)->Z *= k;
	}
}