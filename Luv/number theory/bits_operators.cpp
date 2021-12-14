#include<bits/stdc++.h>
using namespace std;

void printBinary(int n)
{
    for(int i = 16; i >= 0; --i)
    {
        int bit = ((n>>i) & 1);
        cout<<bit;
    }

    cout<<endl;
}

bool checkbitsetornot(int n, int i)
{
    if(n & (1 << i))
        return true;
    
    return false;
}

void setbit(int n, int i)
{
    cout << ( n | (1 << i)) << endl;
}

void unsetbit(int n, int i)
{
    cout << ( n & (~(1<<i)) ) << endl; 
}

void togglebit(int n, int i)
{
    cout << ( n ^ ( 1 << i ) ) << endl;
}

void countbits(int n)
{
    int count = 0;
    while(n!=0)
    {
        if(n & 1)
            count++;
        n = n>>1;
    }

    cout<<count<<endl;
}

int main()
{
    printBinary(9);
    countbits(9);

    /* builtin functions for counting bits */
    cout << __builtin_popcount(9)<<endl; // for integers
    cout << __builtin_popcountll((1LL<<31)-1); // for long long integers
}