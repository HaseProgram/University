#pragma once

template <typename type_t>
IArrayConst<type_t>::IArrayConst(const Array<type_t>& arr)
{
	this->arr = &arr;
	this->currentItem = this->arr->head;
}

template <typename type_t>
IArrayConst<type_t>::~IArrayConst()
{
	this->arr = NULL;//
	this->currentItem = NULL;
}

template <typename type_t>
bool IArrayConst<type_t>::isNULL()
{
	return this->arr == NULL && this->arr->head == NULL;
}

template <typename type_t>
bool IArrayConst<type_t>::operator!()
{
	return this->isNULL();
}

template <typename type_t>
bool IArrayConst<type_t>::check()
{
	return this->currentItem != NULL;
}

template <typename type_t>
size_t IArrayConst<type_t>::count() const
{
	return this->arr->count();
}

template<typename type_t>
void IArrayConst<type_t>::first()
{
	this->currentItem = this->arr->head;
}

template<typename type_t>
void IArrayConst<type_t>::last()
{
	this->currentItem = this->arr->tail;
}

template<typename type_t>
void IArrayConst<type_t>::prev()
{
	item<type_t>* temp = this->arr->head;
	if (temp == this->currentItem)
	{
		this->currentItem = NULL;
		return;
	}
	while (temp->next != this->currentItem)
	{
		temp = temp->next;
	}
	this->currentItem = temp;
}

template<typename type_t>
void IArrayConst<type_t>::next()
{
	this->currentItem = this->currentItem->next;
}

template<typename type_t>
bool IArrayConst<type_t>::getByCount(int index)
{
	this->first();
	int i = 0;
	for (i; i < index && this->check(); i++)
	{
		this->next();
	}
	if (i < index && !this->check())
	{
		throw IteratorAccessElementError();
		return false;
	}
	return true;
}

template<typename type_t>
type_t& IArrayConst<type_t>::value()
{
	return this->currentItem->data;
}

template<typename type_t>
type_t& IArrayConst<type_t>::operator*()
{
	return this->value();
}

template<typename type_t>
IArrayConst<type_t>& IArrayConst<type_t>::operator=(const IArrayConst<type_t>& iterator)
{
	this->currentItem = iterator.currentItem;
	this->arr = iterator.arr;
	return *this;
}

template<typename type_t>
bool IArrayConst<type_t>::operator==(const IArrayConst<type_t>& iterator) const
{
	if (this->arr != iterator.arr)
	{
		throw IteratorCompareError();
	}
	return this->currentItem == iterator.currentItem;
}

template<typename type_t>
bool IArrayConst<type_t>::operator!=(const IArrayConst<type_t>& iterator) const
{
	if (this->arr != iterator.arr)
	{
		throw IteratorCompareError();
	}
	return this->currentItem != iterator.currentItem;
}