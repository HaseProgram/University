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

	int remove(type_t data);

	type_t searchByIndex(size_t index) const;

	void update(size_t index, type_t data) const;

	virtual size_t length() const override;

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
	listItem* item;

	item = new listItem;
	if (!item)
	{
		throw MemoryError();
	}
	item->Prev = NULL;
	item->Next = NULL;
	item->data = data;

	if (this->head == NULL)
	{
		this->head = item;
		this->tail = item;
	}
	else
	{
		item->Prev = this->tail;
		this->tail->Next = item;
		this->tail = item;
	}
	this->size++;
}


template <typename type_t>
void List<type_t>::addfirst(type_t data)
{
	listItem* item;

	item = new listItem;
	if (!item)
	{
		throw MemoryError();
	}
	item->Prev = NULL;
	item->Next = NULL;
	item->data = data;

	if (this->head == NULL)
	{
		this->head = item;
		this->tail = item;
	}
	else
	{
		item->Next = this->head;
		this->head->Prev = item;
		this->head = item;
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
			else
			{
				this->tail = item->Prev;
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