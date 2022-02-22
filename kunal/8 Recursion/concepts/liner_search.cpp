#include<bits/stdc++.h>
using namespace std;



bool linear_search(vector<int> & nums, int start, int target)
{
    if(start == nums.size()) // base condition
        return false;
    
    return nums[start] == target || linear_search(nums, ++start, target);
}

int main()
{
   vector<int> a = {1,2,3,4,5,11};
   cout << boolalpha;
   cout << linear_search(a,0,10);
}