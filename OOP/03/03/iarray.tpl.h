#pragma once

template <typename type_t>
IArray<type_t>::IArray(Array<type_t>& arr)
{
	this->arr = &arr;
	this->currentItem = this->arr->head;
}

template <typename type_t>
IArray<type_t>::~IArray()
{
	this->arr = NULL;//
	this->currentItem = NULL;
}

template <typename type_t>
bool IArray<type_t>::isNULL()
{
	return this->arr == NULL && this->arr->head == NULL;
}

template <typename type_t>
bool IArray<type_t>::operator!()
{
	return this->isNULL();
}

template <typename type_t>
bool IArray<type_t>::check()
{
	return this->currentItem != NULL;
}

template <typename type_t>
size_t IArray<type_t>::count() const
{
	return this->arr->count();
}

template <typename type_t>
type_t& IArray<type_t>::add(type_t& data)
{
	if (!this->check())
	{
		throw IteratorAddError();
	}

	item<type_t>* newItem = new item<type_t>;

	if (!newItem)
	{
		throw MemoryError();
	}

	newItem->data = data;
	newItem->next = this->currentItem->next;
	this->currentItem->next = newItem;

	if (newItem->next == NULL)
	{
		this->arr->tail = newItem;
	}

	this->arr->size++;

	return currentItem->next->data;
}

template <typename type_t>
type_t& IArray<type_t>::remove(bool key)
{
	if (!this->check())
	{
		throw IteratorDeleteError();
	}

	type_t data;

	if (this->arr->head != this->arr->tail)
	{
		item<type_t>* delItem;
		if (this->currentItem == this->arr->head || (this->currentItem != this->arr->tail && key))
		{
			delItem = this->currentItem->next;
			this->currentItem->next = delItem->next;
			data = delItem->data;
			delete delItem;
			delItem = nullptr;
		}
		else
		{
			item<type_t>* prevItem = NULL;

			delItem = this->arr->head;
			while (delItem->next != this->currentItem)
			{
				prevItem = delItem;
				delItem = delItem->next;
			}

			if (prevItem == NULL)
			{
				this->arr->head = currentItem;
			}
			else
			{
				prevItem->next = this->currentItem;
			}
			data = delItem->data;
			delete delItem;
			delItem = nullptr;
		}
	}
	else
	{
		data = this->arr->delItem();
	}

	return data;
}

template<typename type_t>
void IArray<type_t>::clear()
{
	this->arr->clear();
}

template<typename type_t>
void IArray<type_t>::first()
{
	this->currentItem = this->arr->head;
}

template<typename type_t>
void IArray<type_t>::last()
{
	this->currentItem = this->arr->tail;
}

template<typename type_t>
void IArray<type_t>::prev()
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
void IArray<type_t>::next()
{
	this->currentItem = this->currentItem->next;
}

template<typename type_t>
bool IArray<type_t>::getByCount(int index)
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
IArray<type_t>& IArray<type_t>::operator[](int index)
{
	this->getByCount(index);
	return *this;
}

template<typename type_t>
void IArray<type_t>::update(type_t& data)
{
	this->currentItem->data = data;
}

template<typename type_t>
void IArray<type_t>::updatedir(type_t data)
{
	this->currentItem->data = data;
}

template<typename type_t>
void IArray<type_t>::operator=(type_t& data)
{
	this->update(data);
}

template<typename type_t>
type_t& IArray<type_t>::value()
{
	return this->currentItem->data;
}

template<typename type_t>
type_t& IArray<type_t>::operator*()
{
	return this->value();
}

template<typename type_t>
IArray<type_t>& IArray<type_t>::operator=(const IArray<type_t>& iterator)
{
	this->currentItem = iterator.currentItem;
	this->arr = iterator.arr;
	return *this;
}

template<typename type_t>
bool IArray<type_t>::operator==(const IArray<type_t>& iterator) const
{
	if (this->arr != iterator.arr)
	{
		throw IteratorCompareError();
	}
	return this->currentItem == iterator.currentItem;
}

template<typename type_t>
bool IArray<type_t>::operator!=(const IArray<type_t>& iterator) const
{
	if (this->arr != iterator.arr)
	{
		throw IteratorCompareError();
	}
	return this->currentItem != iterator.currentItem;
}