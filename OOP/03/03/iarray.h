#pragma once

/*!
\brief  Iterator for array
\author Dmitry Zaitsev
\version 2.1
\date 22 May 2016

Navigation through array<type_t>
*/

#define IRight TRUE
#define ILeft FALSE

template <class type_t>class Array;

template <class type_t>
class IArray
{
public:
	IArray() {};
	IArray(Array<type_t>&);
	~IArray();

	bool isNULL();
	bool operator !();

	bool check();
	size_t count() const;

	type_t& add(type_t&);
	type_t& remove(bool);

	void clear();

	void first();
	void last();
	void prev();
	void next();
	bool getByCount(int);

	void update(type_t&);
	void operator=(type_t&);

	type_t& value();
	type_t& operator*();

	IArray<type_t>& operator=(const IArray<type_t>&);

	bool operator==(const IArray<type_t>&) const;
	bool operator!=(const IArray<type_t>&) const;

private:
	Array<type_t>* arr;
	item<type_t>* currentItem;
};

#include "iarray.tpl.h"