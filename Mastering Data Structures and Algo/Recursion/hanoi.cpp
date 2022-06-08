#include<iostream>
using namespace std;

void TOH(int num, int t_one, int t_two, int t_three)
{
	if(num <= 0)
		return;
	TOH(num-1, t_one, t_three, t_two);
	cout<<"Move top plate from tower: "<<t_one<<" to tower: "<<t_three<<"\n";
	TOH(num-1, t_two, t_one, t_three);
}

int main()
{
	TOH(3, 1, 2, 3);
}