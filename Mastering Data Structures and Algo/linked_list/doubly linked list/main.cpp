#include<bits/stdc++.h>
// #include "List.h"
using namespace std;

bool isPerfectSquare(int n)
{
	int r = 0;
    while(r * r < n)
        r += 1;
    return (r * r == n);
}

bool prime(int n)
{
    if(n==1||n==0)
    return false;
    if(n%2==0||n%3==0||isPerfectSquare(n))
    return false ;
    for(int i=5;i<10;i+=2)
    {
        if(n%i==0)
        return false;
    }
    return true;

}


int main()
{
	cout<<prime(143);
	
}