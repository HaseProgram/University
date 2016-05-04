#pragma once
#include "iterator_base.h"
#include "iterror.h"

template <class type_t>class List;

template <typename type_t>
class iterator : public iterator_base
{
public:
	iterator(const List<type_t> &list);

	iterator<type_t>& operator=(const iterator<type_t>& right);
	iterator<type_t>& operator[](const size_t& n);				// obj[i]
	iterator<type_t>& operator++();								// ++obj
	iterator<type_t> operator++(type_t);						// obj++
	iterator<type_t>& operator--();								// --obj
	iterator<type_t> operator--(type_t);						// obj--
	void operator>>(type_t& data);							// get value


private:
	const List<type_t>* list;
	void first();
	void prev();
	void next();
	void last();
	bool start();
	bool end();

	const type_t value() const;

};

template <typename type_t>
iterator<type_t>::iterator(const List<type_t> &list)
{
	this->current = 0;
	this->list = &list;
}

template <typename type_t>
void iterator<type_t>::first()
{
	this->current = 0;
}

template <typename type_t>
void iterator<type_t>::last()
{
	this->current = this->list->count() - 1;
}

template <typename type_t>
void iterator<type_t>::next()
{
	this->current++;
}

template <typename type_t>
void iterator<type_t>::prev()
{
	this->current--;
}

template <typename type_t>
bool iterator<type_t>::end()
{
	return this->current == this->list->count() - 1;
}

template <typename type_t>
bool iterator<type_t>::start()
{
	return this->current == 0;
}

template <typename type_t>
const type_t iterator<type_t>::value() const
{
	return this->list->searchByIndex(this->current);
}

template <typename type_t>
iterator<type_t>& iterator<type_t>::operator=(const iterator<type_t>& right)
{
	this->current = right.current;
	this->list = right.list;
	return *this;
}

template <typename type_t>
iterator<type_t>& iterator<type_t>::operator[](const size_t& n)
{
	if (n < 0 || n > this->list->count() - 1)
	{
		throw Index();
	}
	this->first();
	for (int i = 0; i < n; i++)
	{
		this->next();
	}
	return *this;
}

template <typename type_t>
iterator<type_t>& iterator<type_t>::operator++()
{
	if (this->end())
	{
		throw Range();
	}
	this->next();
	return *this;
}

template <typename type_t>
iterator<type_t> iterator<type_t>::operator++(type_t)
{
	iterator<type_t> temp = *this;
	++(*this);
	return temp;
}

template <typename type_t>
iterator<type_t>& iterator<type_t>::operator--()
{
	if (this->start())
	{
		throw Range();
	}
	this->prev();
	return *this;
}

template <typename type_t>
iterator<type_t> iterator<type_t>::operator--(type_t)
{
	iterator<type_t> temp = *this;
	--(*this);
	return temp;
}

template <typename type_t>
void iterator<type_t>::operator>>(type_t& data)
{
	data = this->value();
}
