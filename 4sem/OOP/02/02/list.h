#pragma once
#include "list_base.h"
#include "iterator.h"
#include "citerator.h"
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
	void addbylink(listItem<type_t>* link, type_t data, int key);
	
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

	void clear();
	bool isNULL() const;
	bool operator !() const;

	List<type_t>& operator=(List<type_t> &&right);
	List<type_t> operator+(const List<type_t> &right) const;
	List<type_t>& operator+=(const List<type_t> &right);
	List<type_t>& operator--(type_t);
	List<type_t>& operator--();
	
	bool operator==(const List<type_t> &right) const;
	bool operator!=(const List<type_t> &right) const;

	friend class iterator<typename type_t>;
	friend class citerator<typename type_t>;

	//friend std::ostream& operator<<(std::ostream& stream, List<type_t>& right);
};

#include "_list.h"
