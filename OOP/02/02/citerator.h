#pragma once

#include "iterror.h"

#define lLeft true
#define lRight false

template <class type_t>class List;

template <typename type_t>
class citerator
{
public:
	citerator(const List<type_t> &list);
	~citerator();

	bool isNULL();
	bool operator !();

	bool ready();
	bool isstart();
	bool isend();

	void prev();
	void next();

	const type_t& value();

	citerator<type_t>& operator=(const citerator<type_t>& right);
	citerator<type_t>& operator++();								// ++obj
	citerator<type_t> operator++(type_t);						// obj++
	citerator<type_t>& operator+=(const size_t n);				// obj += n
	citerator<type_t>& operator--();								// --obj
	citerator<type_t> operator--(type_t);						// obj--
	citerator<type_t>& operator-=(const size_t n);				// obj -= n
	const type_t& operator*();										// get value

	bool operator !=(const citerator<type_t>& right) const;
	bool operator ==(const citerator<type_t>& right) const;

	void first();
	void last();

private:
	const List<type_t>* list;
	listItem<type_t>* currentItem;
};

#include "_citerator.h"
