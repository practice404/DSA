#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n < 0)
        {
            n = abs(n);
            x = 1/x;
        }
        if(n==0)
            return 1;
        double temp = myPow(x,n/2); // store in another variable to avoid overflow
        if(n%2)
            return temp*temp*x;
        return temp*temp;   
        
    }
};

int main()
{
    Solution sol;
    int n = INT_MAX;

    cout << sol.myPow(2,INT_MAX);

}