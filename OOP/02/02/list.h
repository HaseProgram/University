#pragma once
#include "list_base.h"
#include "iterator.h"
#include "error.h"
#include <cstdarg>

template <typename type_t>
class List : public list_base
{

private:

	listItem<type_t>* head;
	listItem<type_t>* tail;
	
	List(const List<type_t>& object);

	List<type_t>& operator=(const List<type_t> &right);
	List<type_t>& operator=(List<type_t> &&right);
	void addbylink(listItem<type_t>* link, type_t data, int key);
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
	void deletebylink(listItem<type_t>*, bool key);

	virtual size_t length() const override;
	listItem<type_t>* getHead() const;
	listItem<type_t>* getTail() const;

	void clear();

	List<type_t> operator+(const List<type_t> &right) const;
	List<type_t>& operator+=(const List<type_t> &right);
	List<type_t> operator--(type_t);
	List<type_t>& operator--();
	

	bool operator==(const List<type_t> &right) const;
	bool operator!=(const List<type_t> &right) const;

	friend class iterator<typename type_t>;
};

#include "_list.h"
