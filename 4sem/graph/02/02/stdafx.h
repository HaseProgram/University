// stdafx.h: ���������� ���� ��� ����������� ��������� ���������� ������
// ��� ���������� ������ ��� ����������� �������, ������� ����� ������������, ��
// �� ����� ����������
//

#pragma once

#define ID_TABLE 5000
#define ID_FIRSTCOLUMN 6000
#define ID_EDIT_X 4000
#define ID_EDIT_Y 4001
#define ID_BUTTON_ADD 4002

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // ��������� ����� ������������ ���������� �� ���������� Windows
// ����� ���������� Windows:
#include <windows.h>

// ����� ���������� C RunTime
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <time.h>


// TODO: ���������� ����� ������ �� �������������� ���������, ����������� ��� ���������
#include "resource.h"
#include "structure.h"
#include "interface.h"
#include "draw.h"
#include "triangle.h"
#include <CommCtrl.h>
#include <cmath>