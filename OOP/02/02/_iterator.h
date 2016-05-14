#pragma once

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
bool iterator<type_t>::isNULL()
{
	return this->list && this->list->isNULL();
}

template <typename type_t>
bool iterator<type_t>::operator!()
{
	return this->ready();
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
void iterator<type_t>::update(type_t& data)
{
	if (!this->ready())
	{
		throw WrongLink();
	}
	this->currentItem->data = data;
}

template <typename type_t>
type_t& iterator<type_t>::value()
{
	return this->currentItem->data;
}

template <typename type_t>
iterator<type_t>& iterator<type_t>::operator=(const iterator<type_t>& right)
{
	this->currentItem = right.currentItem;
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
type_t& iterator<type_t>::operator*()
{
	if (!this->ready())
	{
		throw WrongLink();
	}
	return this->value();
}

template <typename type_t>
void iterator<type_t>::operator<<(type_t& data)
{
	this->update(data);
}

template <typename type_t>
bool iterator<type_t>::operator==(const iterator<type_t> &right) const
{
	if (this->list != right.list)
	{
		throw Compare();
	}
	return this->currentItem == right.currentItem;
}

template <typename type_t>
bool iterator<type_t>::operator!=(const iterator<type_t> &right) const
{
	if (this->list != right.list)
	{
		throw Compare();
	}
	return this->currentItem != right.currentItem;
}
