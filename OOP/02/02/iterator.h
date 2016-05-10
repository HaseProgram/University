#pragma once
#include "iterator_base.h"
#include "iterror.h"

#define lLeft true
#define lRight false

template <class type_t>class List;

template <typename type_t>
class iterator : public iterator_base<type_t>
{
public:
	iterator(List<type_t> &list);
	~iterator();

	bool isNULL() const;
	bool operator !() const;
	bool ready();

	void del(bool key);
	void add(type_t data, bool key);

	iterator<type_t>& operator=(const iterator<type_t>& right);
	iterator<type_t>& operator++();								// ++obj
	iterator<type_t> operator++(type_t);						// obj++
	iterator<type_t>& operator+=(const size_t n);				// obj += n
	iterator<type_t>& operator--();								// --obj
	iterator<type_t> operator--(type_t);						// obj--
	iterator<type_t>& operator-=(const size_t n);				// obj -= n
	type_t operator*();											// get value
	void operator<<(type_t data);								// set value

	bool operator !=(const iterator<type_t>& right) const;
	bool operator ==(const iterator<type_t>& right) const;
	bool operator <(const iterator<type_t>& right) const;
	bool operator >(const iterator<type_t>& right) const;
	bool operator <=(const iterator<type_t>& right) const;
	bool operator >=(const iterator<type_t>& right) const;

	void first();
	void last();

private:
	List<type_t>* list;
	void prev();
	void next();

	bool isstart();
	bool isend();

	const type_t value() const;

};

template <typename type_t>
iterator<type_t>::iterator(List<type_t> &list)
{
	this->list = &list;
	this->currentItem = this->list->getHead();
}

template <typename type_t>
iterator<type_t>::~iterator()
{
	this->list = NULL;
	this->currentItem = NULL;
}

template <typename type_t>
bool iterator<type_t>::isend()
{
	return this->currentItem == this->list->getTail();
}

template <typename type_t>
bool iterator<type_t>::isstart()
{
	return this->currentItem this->list->getHead();
}

template <typename type_t>
bool iterator<type_t>::isNULL() const
{
	return this->list->getHead() == NULL;
}

template <typename type_t>
bool iterator<type_t>::operator!() const
{
	return this->isNULL();
}

template <typename type_t>
bool iterator<type_t>::ready()
{
	return this->currentItem != NULL;
}

template <typename type_t>
void iterator<type_t>::add(type_t data, bool key)
{
	this->list->addbylink(this->currentItem, data, key);
}

template <typename type_t>	
void iterator<type_t>::del(bool key)
{
	if (this->ready())
	{
		this->list->deletebylink(this->currentItem, key);
	}
}

template <typename type_t>
void iterator<type_t>::first()
{
	this->currentItem = this->list->getHead();
}

template <typename type_t>
void iterator<type_t>::last()
{
	this->currentItem = this->list->getTail();
}

template <typename type_t>
void iterator<type_t>::next()
{
	if (this->ready())
	{
		this->currentItem = currentItem->Next;
	}
}

template <typename type_t>
void iterator<type_t>::prev()
{
	if (this->ready())
	{
		this->currentItem = currentItem->Prev;
	}
}

template <typename type_t>
const type_t iterator<type_t>::value() const
{
	return this->currentItem->data;
}

template <typename type_t>
iterator<type_t>& iterator<type_t>::operator=(const iterator<type_t>& right)
{
	this->current = right.current;
	this->list = right.list;
	return *this;
}

template <typename type_t>
iterator<type_t>& iterator<type_t>::operator++()
{
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
iterator<type_t>& iterator<type_t>::operator+=(const size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		++(*this);
	}
	return *this;
}


template <typename type_t>
iterator<type_t>& iterator<type_t>::operator--()
{
	if (this->isstart())
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
iterator<type_t>& iterator<type_t>::operator-=(const size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		--(*this);
	}
	return *this;
}


template <typename type_t>
type_t iterator<type_t>::operator*()
{
	return this->value();
}

template <typename type_t>
void iterator<type_t>::operator<<(type_t data)
{
	this->list->update(this->current, data);
}

template <typename type_t>
bool iterator<type_t>::operator==(const iterator<type_t> &right) const
{
	if (this->list != right.list)
		throw Compare();
	return this->current == right.current;
}

template <typename type_t>
bool iterator<type_t>::operator!=(const iterator<type_t> &right) const
{
	if (this->list != right.list)
		throw Compare();
	return this->current != right.current;
}

template <typename type_t>
bool iterator<type_t>::operator<(const iterator<type_t> &right) const
{
	if (this->list != right.list)
		throw Compare();
	return this->current < right.current;
}

template <typename type_t>
bool iterator<type_t>::operator>(const iterator<type_t> &right) const
{
	if (this->list != right.list)
		throw Compare();
	return this->current > right.current;
}

template <typename type_t>
bool iterator<type_t>::operator<=(const iterator<type_t> &right) const
{
	if (this->list != right.list)
		throw Compare();
	return this->current <= right.current;
}

template <typename type_t>
bool iterator<type_t>::operator>=(const iterator<type_t> &right) const
{
	if (this->list != right.list)
		throw Compare();
	return this->current >= right.current;
}