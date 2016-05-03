#pragma once
#include"iterator_base.h"

template <class type_t>class List;

template <typename type_t>
class iterator : public iterator_base
{
public:
	iterator(const List<type_t> &list);

	void first();
	void prev();
	void next();
	void last();

private:
	const List<type_t>* list;

};

template <typename type_t>
iterator<type_t>::iterator(const List<type_t> &list)
{
	this->current = 0;
	this->list = &list;
}