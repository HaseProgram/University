#pragma once

/*!
\brief  Array of some type of objects
\author Dmitry Zaitsev
\version 1.1
\date 22 May 2016

Let to collect some objects to one
*/

#include "exceptionarray.h"

template<typename type_t>
struct item
{
	item* next;
	type_t data;
};

#include "iarray.h"
#include "iarrayconst.h"

class BaseArray
{
public:
	virtual ~BaseArray() {}
	virtual size_t count() const = 0;

protected:
	size_t size;
};

template <typename type_t>
class Array : public BaseArray
{
public:
	Array();
	Array(const Array<type_t>&);
	Array(Array<type_t>&&);
	~Array();

	Array<type_t>& operator=(const Array<type_t>&);

	type_t& addItem(type_t&);
	type_t& delItem();

	void clear();
	
	virtual size_t count() const override;

	friend class IArray<typename type_t>;
	friend class IArrayConst<typename type_t>;

private:
	item<type_t> *head;
	item<type_t> *tail;
};

#include "array.tpl.h"