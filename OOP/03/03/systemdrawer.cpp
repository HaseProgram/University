#include "stdafx.h"
#include "systemdrawer.h"

SystemDrawer::SystemDrawer(tscene scene)
{
	this->scene = scene;
	this->pen = { PS_SOLID , 2, RGB(0,0,0)};
}

SystemDrawer::~SystemDrawer()
{

}

void SystemDrawer::drawline(Point* start, Point* end)
{
	SelectObject(this->scene.hdc, CreatePen(this->pen.style, this->pen.width, this->pen.color));
	MoveToEx(
		this->scene.hdc, 
		start->getX() + (this->scene.x + this->scene.width) / 2,
		start->getY() + (this->scene.y + this->scene.height) / 2,
		NULL
		);
	LineTo(
		this->scene.hdc,
		end->getX() + (this->scene.x + this->scene.width) / 2,
		end->getY() + (this->scene.y + this->scene.height) / 2
		);
}

void SystemDrawer::clearscene()
{
	SelectObject(this->scene.hdc, CreatePen(this->pen.style, this->pen.width, this->pen.color));
	SelectObject(this->scene.hdc, CreateSolidBrush(this->scene.color));
	Rectangle(
		this->scene.hdc, 
		this->scene.x, 
		this->scene.y, 
		this->scene.x + this->scene.width, 
		this->scene.y + this->scene.height
		);
}

void SystemDrawer::setpencolor(int R, int G, int B)
{
	this->pen.color = RGB(R, G, B);
}

void SystemDrawer::setpenwidth(int width)
{
	this->pen.width = width;
}