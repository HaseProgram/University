#pragma once

/*!
\brief  Array of some type of objects
\author Dmitry Zaitsev
\version 1.0
\date 22 May 2016

Let to collect some objects to one
*/

template<typename type_t>
struct item
{
	item* next;
	type_t* data;
};

#include "iarray.h"

class ArrayBase
{
public:
	virtual size_t count() const = 0;

protected:
	size_t size;
};

template <typename type_t>
class Array : public ArrayBase
{
public:
	Array();
	~Array();

	type_t& addItem(type_t&);
	type_t& delItem();

	void clear();
	
	virtual size_t count() const override;

	friend class IArray<typename type_t>;

private:
	item<type_t> *head;
	item<type_t> *tail;
};

#include "array.tpl.h"