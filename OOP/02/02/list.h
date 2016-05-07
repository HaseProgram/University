#pragma once
#include "list_base.h"
#include "iterator.h"
#include "error.h"
#include <cstdarg>

template <typename type_t>
class List : public list_base
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
	
	List(const List<type_t>& object);
	List<type_t>& operator=(const List<type_t> &right);
	void addbyindex(size_t index, type_t data, int key);
	void update(size_t index, type_t data) const;
	
public:
	List();
	
	List(List<type_t>&& object);
	List(size_t size, type_t data, ...);
	~List();

	void addlast(type_t data);
	void addfirst(type_t data);

	void deletelast();
	void deletefirst();
	void deletebyindex(size_t index);

	virtual size_t length() const override;
	type_t searchByIndex(size_t index) const;

	void clear();

	List<type_t> operator+(const List<type_t> &right) const;
	List<type_t>& operator+=(const List<type_t> &right);
	

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
	addbyindex(this->length() - 1, data, lRight);
}

template <typename type_t>
void List<type_t>::addfirst(type_t data)
{
	addbyindex(0, data, lLeft);
}

template <typename type_t>
void List<type_t>::addbyindex(size_t index, type_t data, int key) // добавить по индексу справа или слева
{

	listItem* newItem;
	newItem = new listItem;
	if (!newItem)
	{
		throw MemoryError();
	}

	newItem->data = data;
	newItem->Prev = NULL;
	newItem->Next = NULL;

	listItem* item = this->head;

	if (item == NULL)
	{
		this->head = newItem;
		this->tail = newItem;
	}
	else
	{

		size_t i = 0;
		bool first = false;

		if (key)
		{
			if (index > 0)
				index--;
			else
				first = true;
		}

		for (; i < index && item; i++)
		{
			item = item->Next;
		}
		if (!item || (index >= 0 && i != index))
		{
			throw Index();
		}

		if (!first)
		{
			newItem->Prev = item;
			newItem->Next = NULL;
			if (item->Next)
			{
				newItem->Next = item->Next;
				item->Next->Prev = newItem;
			}
			else
			{
				this->tail = newItem;
			}
			item->Next = newItem;
		}
		else
		{
			newItem->Prev = NULL;
			newItem->Next = item;
			item->Prev = newItem;
			this->head = newItem;
		}
	}
	this->size++;
}

template <typename type_t>
void List<type_t>::deletefirst()
{
	deletebyindex(0);
}

template <typename type_t>
void List<type_t>::deletelast()
{
	deletebyindex(this->length() - 1);
}

template <typename type_t>
void List<type_t>::deletebyindex(size_t index)
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
	if (item->Prev && item->Next)
	{
		item->Next->Prev = item->Prev;
		item->Prev->Next = item->Next;
	}
	else
	{
		if (item->Prev)
		{
			item->Prev->Next = NULL;
			this->tail = this->tail->Prev;
		}
		if (item->Next)
		{
			item->Next->Prev = NULL;
			this->head = this->head->Next;
		}
	}
	delete item;
	this->size--;
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
void List<type_t>::update(size_t index, type_t data) const
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
	item->data = data;
}


template <typename type_t>
size_t List<type_t>::length() const
{
	return this->size;
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
	listItem* item;
	item = right.head;
	while (item)
	{
		this->addlast(item->data);
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

template<typename type_t>
std::ostream& operator<<(std::ostream& stream, const List<type_t>& right)
{

	size_t i = 0;

	for (; i < right.length(); i++)
	{
		stream << right.searchByIndex(i) << " ";
	}
	stream << '\n';
	return stream;
}