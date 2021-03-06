// 2.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"

#include "list.h"
#include "iterator.h"
#include "citerator.h"


int main()
{
	try
	{
		std::cout << "Creating first object MyList with 3 elements: 1,2,3" << std::endl;
		List<int> myList(3, 1, 2, 3);
		std::cout << myList << std::endl;

		std::cout << "Creating second object MyNewList with 2 elements: 4,5" << std::endl;
		List<int> myNewList(2, 4, 5);
		std::cout << myNewList << std::endl;

		std::cout << "Creating third object MyThirdList with 3 elements: 1,2,3" << std::endl;
		List<int> myThirdList(3, 1, 2, 3);
		std::cout << myThirdList << std::endl;

		std::cout << "Adding 0 in beginning of MyThirdList" << std::endl;
		myThirdList.addfirst(0);
		std::cout << myThirdList << std::endl;

		std::cout << "Adding 0 in end of MyThirdList" << std::endl;
		myThirdList.addlast(0);
		std::cout << myThirdList << std::endl;

		std::cout << "Delete first item in MyThirdList" << std::endl;
		myThirdList.deletefirst();
		std::cout << myThirdList << std::endl;

		std::cout << "Delete last item in MyThirdList" << std::endl;
		myThirdList.deletelast();
		std::cout << myThirdList << std::endl;

		std::cout << "MyBigList = MyThirdList + MyList" << std::endl;
		List<int> myBigList = myThirdList + myList;
		std::cout << myBigList << std::endl;

		std::cout << "MyBigList += MyList" << std::endl;
		myBigList += myList;
		std::cout << myBigList << std::endl;

		std::cout << "=========================================================" << std::endl;
		std::cout << std::endl;

		std::cout << "Creating iterator object of myBigList and print value using >>" << std::endl;
		iterator<int> myIterator(myBigList);
		std::cout << *myIterator << std::endl;
		std::cout << std::endl;

		if (!myIterator)
		{
			std::cout << "Checking ! NOT NULL" << std::endl;
		}

		std::cout << "Use ++o and o++ to get next item and print it (>>)" << std::endl;
		++myIterator;
		myIterator++;
		std::cout << *myIterator << std::endl;
		std::cout << std::endl;

		std::cout << "Using last() o.del(lRight)" << std::endl;
		std::cout << myBigList;
		myIterator.last();
		myIterator.del(lLeft);
		std::cout << myBigList << std::endl;

		std::cout << "Using last() o.add(0, lLeft)" << std::endl;
		std::cout << myBigList;
		myIterator.last();
		myIterator.add(0, lLeft);
		std::cout << myBigList << std::endl;

		std::cout << "Using last() o.add(0, lRight)" << std::endl;
		std::cout << myBigList;
		myIterator.last();
		myIterator.add(0, lRight);
		std::cout << myBigList << std::endl;

		myBigList.clear();

		if (!myIterator)
		{
			std::cout << "Checking ! is NULL" << std::endl;
		}
		
		std::cout << "=========================================================" << std::endl;
		std::cout << std::endl;
		
		std::cout << "Using last() o.del(lRight) (Exception)" << std::endl;
		std::cout << myBigList;
		myIterator.last();
		myIterator.del(lRight);
		std::cout << myBigList << std::endl;

		citerator<int> myConstIterator(myBigList);
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

