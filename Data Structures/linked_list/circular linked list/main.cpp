#include<iostream>
#include "List.h"

int main()
{
	List<int> list;
	int arr[] = {1,2,3,4,5};
	list.create(arr, 5);
	list.insert(3,9);
	list.insert(0,-1);
	list.display();

	list.remove(7);
	list.display();
}