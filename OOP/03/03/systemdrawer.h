#pragma once

/*!
\brief  System draw
\author Dmitry Zaitsev
\version 1.0
\date 21 May 2016

Draw line, choose brush, operate with scene (creating, clearing)
*/

#include "basesystemdrawer.h"

class SystemDrawer : public BaseSystemDrawer
{
public:
	SystemDrawer(tscene);
	~SystemDrawer();

	virtual void drawline(Point, Point) override;
	virtual void clearscene() override;
	virtual void setpencolor(int R, int G, int B) override;
	virtual void setpenwidth(int width) override;

private:
	struct tscene scene;
	struct tpen pen;
};