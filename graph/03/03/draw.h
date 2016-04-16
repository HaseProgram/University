#pragma once

#define STANDART 0
#define BREZ_INT 1
#define BREZ_DBL 2
#define BREZ_NST 3
#define CDA 4

typedef struct {
	HDC hdc;
	int x;
	int y;
	int height;
	int width;
	COLORREF bg_color;
	COLORREF ln_color;
	COLORREF BUF;
} scene;

typedef struct {
	int x1, y1;
	int x2, y2;
} line;

void reverse_y(line* Line, int height);
void replace_xy(line* Line, int x, int y);
void draw(int method, scene sceneSettings, line Line);
void draw_sun(int method, int angle, scene sceneSettings);

void standart(scene sceneSettings, line Line);
void brez_int(scene sceneSettings, line Line);
void brez_dbl(scene sceneSettings, line Line);
void brez_nst(scene sceneSettings, line Line);
void cda(scene sceneSettings, line Line);