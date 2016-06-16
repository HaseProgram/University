#pragma once

/*!
\brief  Const iterator for array
\author Dmitry Zaitsev
\version 1.0
\date 17 June 2016

Navigation through array<type_t>
*/

#define IRight TRUE
#define ILeft FALSE

template <class type_t>class Array;

template <class type_t>
class IArrayConst
{
public:
	IArrayConst() {};
	IArrayConst(const Array<type_t>&);
	~IArrayConst();

	bool isNULL();
	bool operator !();

	bool check();
	size_t count() const;

	void first();
	void last();
	void prev();
	void next();
	bool getByCount(int);

	type_t& value();
	type_t& operator*();

	IArrayConst<type_t>& operator=(const IArrayConst<type_t>&);

	bool operator==(const IArrayConst<type_t>&) const;
	bool operator!=(const IArrayConst<type_t>&) const;

private:
	const Array<type_t>* arr;
	item<type_t>* currentItem;
};

#include "iarrayconst.tpl.h"