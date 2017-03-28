// stdafx.h: включаемый файл для стандартных системных включаемых файлов
// или включаемых файлов для конкретного проекта, которые часто используются, но
// не часто изменяются
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Исключите редко используемые компоненты из заголовков Windows
// Файлы заголовков Windows:
#include <windows.h>

// Файлы заголовков C RunTime
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <cmath>

#define ID_EDIT_MOVEX 5000
#define ID_EDIT_MOVEY 5001
#define ID_BUTTON_MOVE 5002
#define ID_EDIT_ROTATEANGLE 5003
#define ID_BUTTON_ROTATE 5004
#define ID_EDIT_SCALEPROPORTIONS 5005
#define ID_EDIT_SCALEX 5006
#define ID_EDIT_SCALEY 5007
#define ID_EDIT_ROTATEX 5008
#define ID_EDIT_ROTATEY 5009
#define ID_BUTTON_SCALE 5010
#define ID_BUTTON_RESET 5011

#define cX 700;
#define cY 500;

#include "draw.h"
#include "operations.h"



// TODO: Установите здесь ссылки на дополнительные заголовки, требующиеся для программы
