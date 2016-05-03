#pragma once
#include "iterator.h"
#include "error.h"
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
	listItem* head;
	listItem* tail;
	size_t size;

public:
	List();
	List(size_t size, type_t data, ...);
	~List();

	void addlast(type_t data);
	void addfirst(type_t data);

	void print();

	friend class iterator<typename type_t>;


};

template <typename type_t>
List<type_t>::List()
{
	this->head = NULL;
	this->tail = NULL;
	this->size = 0;
}

template <typename type_t>
List<type_t>::List(size_t size, type_t data, ...)
{

	this->head = NULL;
	this->tail = NULL;
	this->size = 0;

	va_list arg;
	va_start(arg, data);
	this->addlast(data);
	for (size_t i = 0; i < size - 1; i++)
	{
		data = va_arg(arg, type_t);
		this->addlast(data);
	}
	va_end(arg);
}

template <typename type_t>
List<type_t>::~List()
{

}

template <typename type_t>
void List<type_t>::addlast(type_t data)
{
	listItem* temp;

	temp = new listItem;
	if (!temp)
	{
		throw MemoryError();
	}
	temp->Prev = NULL;
	temp->Next = NULL;
	temp->data = data;

	if (this->head == NULL)
	{
		this->head = temp;
		this->tail = temp;
	}
	else
	{
		temp->Prev = this->tail;
		this->tail->Next = temp;
		this->tail = temp;
	}
	this->size++;
}


template <typename type_t>
void List<type_t>::addfirst(type_t data)
{
	listItem* temp;

	temp = new listItem;
	if (!temp)
	{
		throw MemoryError();
	}
	temp->Prev = NULL;
	temp->Next = NULL;
	temp->data = data;

	if (this->head == NULL)
	{
		this->head = temp;
		this->tail = temp;
	}
	else
	{
		temp->Next = this->head;
		this->head->Prev = temp;
		this->head = temp;
	}
	this->size++;
}


template <typename type_t>
void List<type_t>::print()
{
	listItem* item = this->head;

	if (!item)
	{
		throw PrintError();
	}

	while (item != NULL)
	{
		std::cout << item->data << " ";
		item = item->Next;
	}
	std::cout << std::endl;
}