#include<bits/stdc++.h>
// #include "List.h"


int main()
{
	// List<int> list;
	// for(int i=0; i < 5; i++)
	// 	std::cin >> list;
	// list.insert(0,4);
	// list.display();
	// list.insert(2,10);
	// list.display();
	// list.insert(7,11);
	// list.display();
	// list.remove(7);
	// list.display();
	// list.remove(0);
	// list.display();
	// list.remove(4);
	// list.display();
	// list.reverse();
	// list.display();
	// list.reverse();
	// list[3] = 100;
	// std::cout << list;

	int a, b, c;
	std::cin >> a >> b >> c;

	for(int i = INT_MIN; i<= INT_MAX; i++)
	{
		for(int j = INT_MIN; j<= INT_MAX; j++)
		{
			if((1LL*a*i + 1LL*b*j) == c)
				std::cout<<i<<" " <<j<<std::endl;
		}
	}
}