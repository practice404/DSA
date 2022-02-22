// rotated binary search using recursion

#include<bits/stdc++.h>
using namespace std;

int bs(vector<int> & nums, int target, int start, int end)
{
    if(start > end)
        return -1;
    int mid = start + (end - start)/2;
    if(nums[mid] == target)
        return mid;

    if(nums[start] <= nums[mid])
        if(target >= nums[start] && target < nums[mid])
            return bs(nums, target, start, mid-1);
        else
            return bs(nums, target, mid+1, end);
    if(target > nums[mid] && target <= nums[end])
        return bs(nums, target, mid+1, end);
    return bs(nums, target, start, mid-1);

}

int main()
{
   vector<int> a = {9,1,2,3,5,6,7,8};
   
   auto res = bs(a,9,0,a.size()-1);
   cout << res;
}