#pragma once

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

	listItem<type_t>* item = object.head;

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

	listItem<type_t>* item = object.head;

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
	addbylink(this->getTail(), data, lRight);
}

template <typename type_t>
void List<type_t>::addfirst(type_t data)
{
	addbylink(this->getHead(), data, lLeft);
}

template <typename type_t>
void List<type_t>::addbylink(listItem<type_t>* link, type_t data, int key)
{
	listItem<type_t>* newItem;
	newItem = new listItem<type_t>;
	if (!newItem)
	{
		throw MemoryError();
	}

	newItem->data = data;
	newItem->Prev = NULL;
	newItem->Next = NULL;

	listItem<type_t>* item = link;

	if (item == NULL && this->length() != 0)
	{
		throw WrongLink();
	}

	if (item == NULL)
	{
		this->head = newItem;
		this->tail = newItem;
	}
	else
	{
		bool first = false;

		if (key)
		{
			if (item->Prev != NULL)
			{
				item = item->Prev;
			}
			else
			{
				first = true;
			}
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
	if (!this->getHead()->Next)
	{
		throw Last();
	}
	deletebylink(this->getHead()->Next, true);
}

template <typename type_t>
void List<type_t>::deletelast()
{
	if (!this->getTail().Prev)
	{
		throw Last();
	}
	deletebylink(this->getTail()->Prev, false);
}

template <typename type_t>
void List<type_t>::deletebylink(listItem<type_t>* link, bool key)
{
	listItem<type_t>* item = link;

	if (item == NULL)
	{
		throw WrongLink();
	}

	if (key)
	{
		if (item->Prev == NULL)
		{
			throw WrongLink();
		}
		item = item->Prev;
	}
	else
	{
		if (item->Next == NULL)
		{
			throw WrongLink();
		}
		item = item->Next;
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
bool List<type_t>::isNULL() const
{
	return this->getHead() == NULL;
}

template <typename type_t>
bool List<type_t>::operator!() const
{
	return this->isNULL();
}

template <typename type_t>
List<type_t>& List<type_t>::operator=(List<type_t> &&right)
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

	listItem<type_t>* item;
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
	listItem<type_t>* item;
	item = right.head;
	while (item)
	{
		this->addlast(item->data);
		item = item->Next;
	}
	return *this;
}

template <typename type_t>
List<type_t>& List<type_t>::operator--(type_t)
{
	this->deletelast();
}

template <typename type_t>
List<type_t>& List<type_t>::operator--()
{
	this->deletefirst();
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
	while (item1  && item1->data != item2->data)
	{
		item1 = item1->Next;
		item2 = item2->Next;
	}

	return !item1;
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
std::ostream& operator<<(std::ostream& stream, List<type_t>& right)
{
	listItem<type_t>* item = right.getHead();

	while (item)
	{
		stream << item->data << " ";
		item = item->Next;
	}
	stream << '\n';
	return stream;
}
