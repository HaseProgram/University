#pragma once

template <typename type_t>
Array<type_t>::Array()
{
	this->head = NULL;
	this->tail = NULL;
	this->size = 0;
}

template <typename type_t>
Array<type_t>::Array(const Array<type_t>& cvarray)
{
	this->head = NULL;
	this->tail = NULL;
	this->size = 0;

	item<type_t>* tempItem = cvarray.head;

	while (tempItem != NULL)
	{
		this->addItem(tempItem->data);
		tempItem = tempItem->next;
	}
}

template <typename type_t>
Array<type_t>::Array(Array<type_t>&& rvarray)
{
	this->head = NULL;
	this->tail = NULL;
	this->size = 0;

	item<type_t>* tempItem = rvarray.head;

	while (tempItem != NULL)
	{
		this->addItem(tempItem->data);
		tempItem = tempItem->next;
	}
}

template <typename type_t>
Array<type_t>::~Array()
{
	this->clear();
}

template <typename type_t>
Array<type_t>& Array<type_t>::operator=(const Array<type_t>& cvarray)
{
	this->clear();

	item<type_t>* tempItem = cvarray.head;

	while (tempItem != NULL)
	{
		this->addItem(tempItem->data);
		tempItem = tempItem->next;
	}

	return *this;
}

template <typename type_t>
type_t& Array<type_t>::addItem(type_t& data)
{
	item<type_t>* newItem = new item<type_t>;
	if (!newItem)
	{
		throw MemoryError();
	}

	newItem->data = data;
	newItem->next = NULL;

	if (this->head == NULL)
	{
		this->head = newItem;
		this->tail = this->head;
	}
	else
	{
		this->tail->next = newItem;
		this->tail = this->tail->next;
	}

	this->size++;

	return this->tail->data;
}

template <typename type_t>
type_t& Array<type_t>::delItem()
{
	if (this->head == NULL)
	{
		throw DeleteItemError();
	}

	type_t* data = this->tail->data;

	delete this->tail;
	this->tail = nullptr;
	this->size--;
	
	item<type_t>* temp = this->head;
	while (temp && temp->next != NULL)
	{
		temp = temp->next;
	}
	this->tail = temp;

	return data;
}


template <typename type_t>
void Array<type_t>::clear()
{
	while (this->head)
	{
		this->tail = this->head->next;
		delete this->head;
		this->head = this->tail;
	}
	this->size = 0;
}

template <typename type_t>
size_t Array<type_t>::count() const
{
	return this->size;
}