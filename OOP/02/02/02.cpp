// 2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include "list.h"
#include "iterator.h"


int main()
{
	try
	{
		std::cout << "Creating first object MyList with 3 elements: 1,2,3" << std::endl;
		List<int> myList(3, 1, 2, 3);
		myList.print();
		std::cout << std::endl;

		std::cout << "Creating second object MyNewList with 2 elements: 4,5" << std::endl;
		List<int> myNewList(2, 4, 5);
		myNewList.print();
		std::cout << std::endl;

		std::cout << "MyList = MyNewList; Print MyList" << std::endl;
		myList = myNewList;
		myList.print();
		std::cout << std::endl;

		std::cout << "Creating third object MyThirdList with 3 elements: 1,2,3" << std::endl;
		List<int> myThirdList(3, 1, 2, 3);
		myThirdList.print();
		std::cout << std::endl;

		std::cout << "Adding 0 in beginning of MyThirdList" << std::endl;
		myThirdList.addfirst(0);
		myThirdList.print();
		std::cout << std::endl;

		std::cout << "Adding 4 in end of MyThirdList" << std::endl;
		myThirdList.addlast(4);
		myThirdList.print();
		std::cout << std::endl;

		std::cout << "Removing 0 in MyThirdList" << std::endl;
		myThirdList.remove(0);
		myThirdList.print();
		std::cout << std::endl;

		std::cout << "Creating MyBigList = MyThirdList - MyList" << std::endl;
		List<int> myBigList = myThirdList - myList;
		myBigList.print();
		std::cout << std::endl;

		std::cout << "MyBigList = MyThirdList + MyList" << std::endl;
		myBigList = myThirdList + myList;
		myBigList.print();
		std::cout << std::endl;

		std::cout << "MyBigList = MyBigList + MyList" << std::endl;
		myBigList = myBigList + myList;
		myBigList.print();
		std::cout << std::endl;

		std::cout << "MyBigList (1) update -> 9" << std::endl;
		myBigList.update(0, 9);
		myBigList.print();
		std::cout << std::endl;

		std::cout << "=========================================================" << std::endl;
		std::cout << std::endl;
		int value;

		std::cout << "Creating iterator object of myBigList and print value using >>" << std::endl;
		iterator<int> myIterator(myBigList);
		myIterator >> value;
		std::cout << value << std::endl;
		std::cout << std::endl;

		std::cout << "Use ++o and o++ to get next item and print it (>>)" << std::endl;
		++myIterator;
		myIterator++;
		myIterator >> value;
		std::cout << value << std::endl;
		std::cout << std::endl;

		std::cout << "Using [5] to get 5 item and print it (>>)" << std::endl;
		myIterator[5] >> value;
		std::cout << value << std::endl;
		std::cout << std::endl;

		std::cout << "Using [2] << 9 to set 9 in 2item and print it (>>)" << std::endl;
		myIterator[2] << 9;
		myIterator[2] >> value;
		std::cout << value << std::endl;
		std::cout << std::endl;

		std::cout << "=========================================================" << std::endl;
		std::cout << std::endl;

		std::cout << "MyList -= MyigList (exception)" << std::endl;
		myList -= myBigList;
		myList.print();
		
	}
	catch (Error &err)
	{
		std::cout << err.out() << std::endl;
	}
	catch (ItError &err)
	{
		std::cout << err.out() << std::endl;
	}

	system("pause");
	return 0;
}

