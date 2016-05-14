#pragma once
#include "iterror.h"

#define lLeft true
#define lRight false

template <class type_t>class List;

template <typename type_t>
class iterator
{
public:
	iterator(List<type_t> &list);
	~iterator();

	bool isNULL();
	bool operator !();

	bool ready();
	bool isstart();
	bool isend();

	void del(bool key);
	void add(type_t data, bool key);

	void prev();
	void next();

	void update(type_t& data);

	type_t& value();

	iterator<type_t>& operator=(const iterator<type_t>& right);
	iterator<type_t>& operator++();								// ++obj
	iterator<type_t> operator++(type_t);						// obj++
	iterator<type_t>& operator+=(const size_t n);				// obj += n
	iterator<type_t>& operator--();								// --obj
	iterator<type_t> operator--(type_t);						// obj--
	iterator<type_t>& operator-=(const size_t n);				// obj -= n
	type_t& operator*();										// get value
	void operator<<(type_t& data);								// set value

	bool operator !=(const iterator<type_t>& right) const;
	bool operator ==(const iterator<type_t>& right) const;

	void first();
	void last();

private:
	List<type_t>* list;
	listItem<type_t>* currentItem;
};

#include "_iterator.h"
