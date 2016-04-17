#pragma once

typedef enum {
	ELLIPSE, CIRCLE, SPEKTRE
} efigure;

typedef struct {
	int centerX, centerY;
	int width, height;
	int radiusMin, radiusMax;
	int radiusStep;
} params;

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

void draw(efigure figure, params parameters, int alg, scene sceneSettings);

void ellipse_parameters(params parameters, scene sceneSettings);
void ellipse_average(params parameters, scene sceneSettings);
void ellipse_standart(params parameters, scene sceneSettings);

void circle_equantion(params parameters, scene sceneSettings);
void circle_parameters(params parameters, scene sceneSettings);
void circle_brezenhem(params parameters, scene sceneSettings);
void circle_average(params parameters, scene sceneSettings);
void circle_standart(params parameters, scene sceneSettings);

void spektre(int alg, params parameters, scene sceneSettings);