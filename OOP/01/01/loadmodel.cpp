#include "stdafx.h"
#include "model.h"
#include "loadmodel.h"
#include "convertstring.h"

char* get_model_name()
{
	char *modelFileName;
	char bufFileName[MAX_PATH * 2] = "";
	OPENFILENAME ofn;

	ZeroMemory(&ofn, sizeof(OPENFILENAME));

	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = NULL;
	ofn.lpstrFilter = (LPCWSTR)TEXT("3D model (*.model)\0*.model\0 All files (*.*)\0*.*\0");
	ofn.lpstrFile = (LPWSTR)bufFileName;
	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrTitle = (LPCWSTR)TEXT("Choose 3D model file");
	ofn.Flags = OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
	ofn.lpstrDefExt = (LPCWSTR)TEXT("*.model");

	if (GetOpenFileName(&ofn))
	{
		delete_zero_symbols(bufFileName);
		modelFileName = (char*)calloc(strlen(bufFileName) + 1, sizeof(char));
		strcpy(modelFileName, bufFileName);
		return modelFileName;
	}
	else
	{
		return NULL;
	}
}

int load_model(char* modelFileName)
{
	struct view View;
	if (!modelFileName)
	{
		return BAD_FILE_NAME;
	}
	View.Model.file = open_model(modelFileName);
	if (!View.Model.file)
	{
		return CANT_OPEN_FILE;
	}
	int error = transfer(View.Model.file);
}

int transfer(FILE* modelFile)
{
	int error = OK;
	struct view View;

	error = read_scene(modelFile, &View);
	if (error != OK)
		return error;
	error = read_nodes_and_edges_number(modelFile, &View);
	if (error != OK)
		return error;
}

int read_scene(FILE* modelFile, struct view* View)
{
	if (fscanf_s(modelFile, "%d %d", &View->Scene.height, &View->Scene.width) == 2)
		return OK;
	return BAD_SCENE_PARAMS;
}

int read_nodes_and_edges_number(FILE* modelFile, struct view* View)
{
	if (fscanf_s(modelFile, "%d %d", &View->Model.Node.Number, &View->Model.Edge.Number) == 2)
		return OK;
	return BAD_NUMBERS_OF_ITEMS;
}

int read

FILE* open_model(char* modelFileName)
{
	FILE* modelFile = fopen(modelFileName, "r");
	return modelFile;
}