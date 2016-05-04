// 2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include "list.h"
#include "iterator.h"


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

	//myBigList.remove(0);
	//myBigList.print();

	myBigList.remove(2);
	//myBigList.print();

	//myBigList.remove(7);
	//myBigList.print();

	//std::cout << myBigList.count() << std::endl;

	myList.print();
	myList = myList - myBigList;
	myList.print();

	////////////////////////////////////////////////////////////

	if (myList == myList)
	{
		std::cout << "== worked nice (it was ==)" << std::endl;
	}
	else
	{
		std::cout << "== worked bad (it was ==)" << std::endl;
	}
	
	if (myList == myBigList)
	{
		std::cout << "== worked bad (it was !=)" << std::endl;
	}
	else
	{
		std::cout << "== worked nice (it was !=)" << std::endl;
	}

	////////////////////////////////////////////////////////////

	if (myList != myList)
	{
		std::cout << "!= worked bad (it was !=)" << std::endl;
	}
	else
	{
		std::cout << "!= worked nice (it was !=)" << std::endl;
	}

	if (myList != myBigList)
	{
		std::cout << "!= worked nice (it was !=)" << std::endl;
	}
	else
	{
		std::cout << "!= worked bad (it was !=)" << std::endl;
	}

	////////////////////////////////////////////////////////////

	myBigList += myList;
	myBigList.print();
	myBigList += myBigList;
	myBigList.print();
	myList += myList;
	myList.print();

	system("pause");
	return 0;
}

