#include <iostream>
#include "LinkedList.cpp"
using namespace std;

int main()
{
	LinkedList* newList = LinkedList::CreateNewLList(1);
	newList->AppendElementInLList(2)->AppendElementInLList(3);
	newList->printLList();
	newList->DeleteElementInLList(1);
	newList->printLList();
	newList->PrependElementInLList(13);
	newList->printLList();
	newList->DeleteElementInLList(3);
	newList->printLList();
	newList->DeleteLList();
	newList->printLList();
	_fgetchar();
	return 0;
}