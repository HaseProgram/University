#include "stdafx.h"
#include "modifymodel.h"
#include "model.h"

void modify_model(struct model* modelSettings, struct modification_params modificationSettings)
{
	switch (modificationSettings.type)
	{
	case ROTATE_XZ:
		rot_xz(modelSettings, modificationSettings);
		break;
	case ROTATE_XY:
		rot_xy(modelSettings, modificationSettings);
		break;
	case ZOOM:
		zoom(modelSettings, modificationSettings);
		break;
	}
}

void rot_xz(struct model* modelSettings, struct modification_params modificationSettings)
{
	double teta = (modificationSettings.param) / 180.0 * M_PI;
	double newX, newZ;

	struct node* nodeArray = &modelSettings->Node;
	struct nodecoordinates *nodeCoords = nodeArray->Items;

	for (int i = 0; i < nodeArray->Number; i++)
	{
		newX = nodeCoords[i].X * cos(teta) + nodeCoords[i].Z * sin(teta);
		newZ = nodeCoords[i].Z * cos(teta) - nodeCoords[i].X * sin(teta);
		nodeCoords[i].X = newX;
		nodeCoords[i].Z = newZ;
	}
}

void rot_xy(struct model* modelSettings, struct modification_params modificationSettings)
{
	double teta = (modificationSettings.param) / 180.0 * M_PI;
	double newX, newY;

	struct node* nodeArray = &modelSettings->Node;
	struct nodecoordinates *nodeCoords = nodeArray->Items;

	for (int i = 0; i < nodeArray->Number; i++)
	{

		newX = nodeCoords[i].X * cos(teta) + nodeCoords[i].Y * sin(teta);
		newY = nodeCoords[i].Y * cos(teta) - nodeCoords[i].X * sin(teta);
		nodeCoords[i].X = newX;
		nodeCoords[i].Y = newY;
	}
}

void zoom(struct model* modelSettings, struct modification_params modificationSettings)
{
	double k = modificationSettings.param;

	struct node* nodeArray = &modelSettings->Node;
	struct nodecoordinates *nodeCoords = nodeArray->Items;

	for (int i = 0; i < nodeArray->Number; i++)
	{
		nodeCoords[i].X *= k;
		nodeCoords[i].Y *= k;
		nodeCoords[i].Z *= k;
	}
}