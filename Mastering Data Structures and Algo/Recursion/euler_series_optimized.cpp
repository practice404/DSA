#include<iostream>
using namespace std;
 
double fun(int n, int m)
{
    static double s = 1;
    if(m == 0)
        return s;
    s = (1+n*s/m);
    return fun(n,m-1);
}

int main()
{
    cout<<fun(2,10);
}