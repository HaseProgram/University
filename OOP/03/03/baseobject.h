#pragma once

/*!
\brief  Base object
\author Dmitry Zaitsev
\version 2.0
\date 29 May 2016

Set base interface for any object
*/

class BaseObject
{
public:
	virtual void add(BaseObject*)
	{
	}

	virtual void modificate() = 0;
};