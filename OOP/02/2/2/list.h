#pragma once
#include "iterator.h"
#include <cstdarg>

template <typename type_t>
class List
{

struct listItem
{
	listItem* Prev;
	listItem* Next;
	type_t data;
};

private:
	listItem* item;
	size_t size;

public:
	List();
	List(size_t size, type_t data, ...);
	~List();

	friend class iterator<typename type_t>;


};

template <typename type_t>
List<type_t>::List()
{
	this->item = NULL;
}

template <typename type_t>
List<type_t>::List(size_t size, type_t data, ...)
{
	this->size = size;
	va_list arg;
	va_start(arg, data);
	this->item = new listItem;
	this->item->Prev = NULL;
	this->item->Next = NULL;
	this->item->data = data;

	listItem* temp;

	for (size_t i = 0; i < size - 1; i++)
	{
		temp = new listItem;
		temp->Prev = this->item;
		temp->Next = NULL;
		temp->data = va_arg(arg, type_t);
		this->item->Next = temp;
		this->item = this->item->Next;
	}
	va_end(arg);
}

template <typename type_t>
List<type_t>::~List()
{

}