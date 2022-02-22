#include<bits/stdc++.h>
using namespace std;



bool is_sort(vector<int> & nums, int start)
{
    if(start == nums.size()-1) // base condition
        return true;
    
    return nums[start] <= nums[start+1] && is_sort(nums, ++start);
}

int main()
{
   vector<int> a = {1,2,3,4,5,11};
   cout << boolalpha;
   cout << is_sort(a,0);
}