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
	List(const List<type_t>& object);
	List(List<type_t>&& object);
	List(size_t size, type_t data, ...);
	~List();

	void addlast(type_t data);
	void addfirst(type_t data);

	int remove(type_t data);

	type_t searchByIndex(size_t index) const;

	int count() const;

	void print();

	void clear();

	List<type_t>& operator=(const List<type_t> &right);
	List<type_t> operator+(const List<type_t> &right) const;
	List<type_t>& operator+=(const List<type_t> &right);
	List<type_t> operator-(const List<type_t> &right) const;
	List<type_t>& operator-=(const List<type_t> &right);

	bool operator==(const List<type_t> &right) const;
	bool operator!=(const List<type_t> &right) const;


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
List<type_t>::List(const List<type_t>& object)
{
	this->head = NULL;
	this->tail = NULL;
	this->size = 0;

	listItem* item = object.head;

	while (item != NULL)
	{
		this->addlast(item->data);
		item = item->Next;
	}
}

template <typename type_t>
List<type_t>::List(List<type_t>&& object)
{
	this->head = NULL;
	this->tail = NULL;
	this->size = 0;

	listItem* item = object.head;

	while (item != NULL)
	{
		this->addlast(item->data);
		item = item->Next;
	}
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
	clear();
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
int List<type_t>::remove(type_t data)
{
	int deleted = 0;
	listItem* item = this->head;
	listItem* next;

	while (item)
	{
		next = item->Next;
		if (item->data == data)
		{
			if (item->Prev)
			{
				item->Prev->Next = item->Next;
			}
			else 
			{
				this->head = item->Next;
			}
			if (item->Next)
			{
				item->Next->Prev = item->Prev;
			}
			delete item;
			deleted++;
			this->size--;
		}
		item = next;
	}
	return deleted;
}


template<typename type_t>
type_t List<type_t>::searchByIndex(size_t index) const
{
	listItem* item = this->head;
	
	size_t i = 0;
	for (; i < index && item; i++)
	{
		item = item->Next;
	}
	if (!item || i != index)
	{
		throw Index();
	}
	return item->data;
}


template <typename type_t>
int List<type_t>::count() const
{
	return this->size;
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

template <typename type_t>
void List<type_t>::clear()
{
	while (this->head)
	{
		this->tail = this->head->Next;
		delete this->head;
		this->head = this->tail;
	}
	this->size = 0;
}

template <typename type_t>
List<type_t>& List<type_t>::operator=(const List<type_t> &right)
{
	if (*this != right)
	{
		this->clear();

		listItem* item = right.head;

		while (item != NULL)
		{
			this->addlast(item->data);
			item = item->Next;
		}
	}
	return *this;
}

template <typename type_t>
List<type_t> List<type_t>::operator+(const List<type_t> &right) const
{
	List<type_t> result = *this;

	result.size += right.size;

	listItem* item;
	item = right.head;

	while (item)
	{
		result.addlast(item->data);
		item = item->Next;
	}
	return result;
}


template <typename type_t>
List<type_t>& List<type_t>::operator+=(const List<type_t> &right)
{
	List<type_t> temp = right;

	listItem* item;
	item = temp.head;
	while (item)
	{
		this->addlast(item->data);
		item = item->Next;
	}
	return *this;
}

template <typename type_t>
List<type_t> List<type_t>::operator-(const List<type_t> &right) const
{
	List<type_t> result = *this;

	listItem* item;
	item = right.head;

	while (item)
	{
		result.remove(item->data);
		item = item->Next;
	}
	return result;
}

template <typename type_t>
List<type_t>& List<type_t>::operator-=(const List<type_t> &right)
{
	List<type_t> temp = right;

	listItem* item;
	item = temp.head;
	while (item)
	{
		this->remove(item->data);
		item = item->Next;
	}
	return *this;
}

template <typename type_t>
bool List<type_t>::operator==(const List<type_t> &right) const
{
	if (this->size != right.size)
	{
		return false;
	}
	listItem* item1 = this->head;
	listItem* item2 = right.head;
	while (item1)
	{
		if (item1->data != item2->data)
		{
			return false;
		}
		item1 = item1->Next;
		item2 = item2->Next;
	}
	return true;
}

template <typename type_t>
bool List<type_t>::operator!=(const List<type_t> &right) const
{
	if (this->size != right.size)
	{
		return true;
	}
	listItem* item1 = this->head;
	listItem* item2 = right.head;
	while (item1 && item2)
	{
		if (item1->data != item2->data)
		{
			return true;
		}
		item1 = item1->Next;
		item2 = item2->Next;
	}
	return false;
}
