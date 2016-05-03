// 2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include "list.h"
#include "iterator.h"
//using namespace std;



int main()
{
	List<int> myList(3, 1, 2, 3);
	myList.addlast(4);
	myList.addfirst(0);
	myList.print();

	List<int> myNewList(3, 5, 6, 7);

	List<int> myVeryNewList = myNewList;
	myVeryNewList.print();

	List<int> myBigList;
	myBigList = myList + myNewList;
	myBigList.print();

	system("pause");
	return 0;
}

