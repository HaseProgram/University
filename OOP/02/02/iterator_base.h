#pragma once
#include "list_struct.h"

template <typename type_t>
class iterator_base
{

public:
	virtual void first() = 0;
	virtual void prev() = 0;
	virtual void next() = 0;
	virtual void last() = 0;

protected:
	listItem<type_t>* currentItem;
};