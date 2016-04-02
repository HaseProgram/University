#include "stdafx.h"
#include "interface.h"
#include "convertstring.h"
#include "draw.h"

extern HWND hWnd;
extern HINSTANCE hInst;

void init_context(struct context_params* sceneSettings)
{
	sceneSettings->hdc = GetDC(hWnd);
	sceneSettings->x = 405;
	sceneSettings->y = 15;
	sceneSettings->height = 670;
	sceneSettings->width = 1000;
	sceneSettings->bg_color = 0xFAF9FA;
	sceneSettings->ln_color = 0x48333A;
}

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

void initButtons()
{
	CreateWindowW(TEXT("BUTTON"), TEXT("Rotate ↑"),
		WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
		135, 15 + 200, 100, 50, 
		hWnd, (HMENU)ID_BUTTON_ROTATE_UP, hInst, NULL);

	CreateWindowW(TEXT("BUTTON"), TEXT("Rotate ←"),
		WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
		15, 100 + 200, 100, 50,
		hWnd, (HMENU)ID_BUTTON_ROTATE_LEFT, hInst, NULL);

	CreateWindowW(TEXT("BUTTON"), TEXT("Rotate →"),
		WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
		260, 100 + 200, 100, 50,
		hWnd, (HMENU)ID_BUTTON_ROTATE_RIGHT, hInst, NULL);

	CreateWindowW(TEXT("BUTTON"), TEXT("Rotate ↓"),
		WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
		135, 185 + 200, 100, 50,
		hWnd, (HMENU)ID_BUTTON_ROTATE_DOWN, hInst, NULL);

	CreateWindowW(TEXT("BUTTON"), TEXT("Zoom +"),
		WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
		135, 100 + 200, 100, 25,
		hWnd, (HMENU)ID_BUTTON_ZOOM_IN, hInst, NULL);

	CreateWindowW(TEXT("BUTTON"), TEXT("Zoom -"),
		WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
		135, 125 + 200, 100, 25,
		hWnd, (HMENU)ID_BUTTON_ZOOM_OUT, hInst, NULL);

}