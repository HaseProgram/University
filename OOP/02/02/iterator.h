#pragma once
#include "iterator_base.h"
#include "iterror.h"

#define lLeft true
#define lRight false

template <class type_t>class List;

template <typename type_t>
class iterator : public iterator_base
{
public:
	iterator(List<type_t> &list);
	~iterator();

	void del(bool key);

	iterator<type_t>& operator=(const iterator<type_t>& right);
	iterator<type_t>& operator[](const size_t& n);				// obj[i]
	iterator<type_t>& operator++();								// ++obj
	iterator<type_t> operator++(type_t);						// obj++
	iterator<type_t>& operator+=(const size_t n);				// obj += n
	iterator<type_t>& operator--();								// --obj
	iterator<type_t> operator--(type_t);						// obj--
	iterator<type_t>& operator-=(const size_t n);				// obj -= n
	void operator*(type_t& data);								// get value
	void operator<<(type_t data);								// set value

	bool operator !=(const iterator<type_t>& right) const;
	bool operator ==(const iterator<type_t>& right) const;
	bool operator <(const iterator<type_t>& right) const;
	bool operator >(const iterator<type_t>& right) const;
	bool operator <=(const iterator<type_t>& right) const;
	bool operator >=(const iterator<type_t>& right) const;

private:
	List<type_t>* list;
	void first();
	void prev();
	void next();
	void last();

	bool isstart();
	bool isend();

	const type_t value() const;

};

template <typename type_t>
iterator<type_t>::iterator(List<type_t> &list)
{
	this->current = 0;
	this->list = &list;
}

template <typename type_t>
iterator<type_t>::~iterator()
{
	this->current = 0;
	this->list = NULL;
}

template <typename type_t>	
void iterator<type_t>::del(bool key)
{
	if (key)
	{
		if (isstart())
		{
			throw Range();
		}
		this->list->deletebyindex(this->current - 1);
		this->current--;
	}
	else
	{
		if (isend())
		{
			throw Range();
		}
		this->list->deletebyindex(this->current + 1);
	}
}

template <typename type_t>
void iterator<type_t>::first()
{
	this->current = 0;
}

template <typename type_t>
void iterator<type_t>::last()
{
	this->current = this->list->length() - 1;
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
bool iterator<type_t>::isend()
{
	return this->current >= this->list->length() - 1;
}

template <typename type_t>
bool iterator<type_t>::isstart()
{
	return this->current <= 0;
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
	if (n < 0 || n > this->list->length() - 1)
	{
		throw Index();
	}
	this->first();
	for (size_t i = 0; i < n; i++)
	{
		this->next();
	}
	return *this;
}

template <typename type_t>
iterator<type_t>& iterator<type_t>::operator++()
{
	if (this->isend())
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
void iterator<type_t>::operator*(type_t& data)
{
	data = this->value();
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