#include<iostream>
using namespace std;

int F[1000] = {-1};

int fun(int n)
{
    if(n <= 1)
    {
        F[n] = n;
        return F[n];
    }

    else
    {
        if(F[n-1] == -1)
            F[n-1] = fun(n-1);
        if(F[n-2] == -1)
            F[n-2] = fun(n-2);
    }

    return F[n-1]+F[n-2];
}

int main()
{   
	for(auto &i : F)
		i = -1;
    cout<<fun(7);
}