#pragma once

template <typename type_t>
citerator<type_t>::citerator(const List<type_t> &list)
{
	this->list = &list;
	this->currentItem = this->list->getHeadConst();
}

template <typename type_t>
citerator<type_t>::~citerator()
{
	this->list = NULL;
	this->currentItem = NULL;
}

template <typename type_t>
bool citerator<type_t>::isend()
{
	return this->currentItem == this->list->getTailConst();
}

template <typename type_t>
bool citerator<type_t>::isstart()
{
	return this->currentItem this->list->getHeadConst();
}

template <typename type_t>
bool citerator<type_t>::isNULL()
{
	return this->list && this->list->isNULL();
}

template <typename type_t>
bool citerator<type_t>::operator!()
{
	return this->ready();
}

template <typename type_t>
bool citerator<type_t>::ready()
{
	return this->currentItem != NULL;
}

template <typename type_t>
void citerator<type_t>::first()
{
	this->currentItem = this->list->getHeadConst();
}

template <typename type_t>
void citerator<type_t>::last()
{
	this->currentItem = this->list->getTail();
}

template <typename type_t>
void citerator<type_t>::next()
{
	if (this->ready())
	{
		this->currentItem = currentItem->Next;
	}
}

template <typename type_t>
void citerator<type_t>::prev()
{
	if (this->ready())
	{
		this->currentItem = currentItem->Prev;
	}
}

template <typename type_t>
const type_t& citerator<type_t>::value()
{
	return this->currentItem->data;
}

template <typename type_t>
citerator<type_t>& citerator<type_t>::operator=(const citerator<type_t>& right)
{
	this->currentItem = right.currentItem;
	this->list = right.list;
	return *this;
}

template <typename type_t>
citerator<type_t>& citerator<type_t>::operator++()
{
	this->next();
	return *this;
}

template <typename type_t>
citerator<type_t> citerator<type_t>::operator++(type_t)
{
	citerator<type_t> temp = *this;
	++(*this);
	return temp;
}

template <typename type_t>
citerator<type_t>& citerator<type_t>::operator+=(const size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		++(*this);
	}
	return *this;
}

template <typename type_t>
citerator<type_t>& citerator<type_t>::operator--()
{
	this->prev();
	return *this;
}

template <typename type_t>
citerator<type_t> citerator<type_t>::operator--(type_t)
{
	citerator<type_t> temp = *this;
	--(*this);
	return temp;
}

template <typename type_t>
citerator<type_t>& citerator<type_t>::operator-=(const size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		--(*this);
	}
	return *this;
}

template <typename type_t>
const type_t& citerator<type_t>::operator*()
{
	if (!this->ready())
	{
		throw WrongLink();
	}
	return this->value();
}

template <typename type_t>
bool citerator<type_t>::operator==(const citerator<type_t> &right) const
{
	if (this->list != right.list)
	{
		throw Compare();
	}
	return this->currentItem == right.currentItem;
}

template <typename type_t>
bool citerator<type_t>::operator!=(const citerator<type_t> &right) const
{
	if (this->list != right.list)
	{
		throw Compare();
	}
	return this->currentItem != right.currentItem;
}
