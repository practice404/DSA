#include<bits/stdc++.h>
using namespace std;

void bsort(vector<int> & nums, int i, int j)
{
    if(i == nums.size())
        return;
    if(j < nums.size() - 1 - i)
    {
        if(nums[j] > nums[j+1])
            swap(nums[j], nums[j+1]);
        bsort(nums, i, ++j);
    }
    else
        bsort(nums, ++i,0);
    /*
    for(int i=0; i < nums.size(); i++)
    {
        for(int j = 0; j < nums.size()-1-i; j++)
            if(nums[j] > nums[j+1])
                swap(nums[j], nums[j+1]);
    }
    */
}

int main()
{
    vector<int> v = {4,3,2,1,7};
    bsort(v,0,0);
    for(auto i : v)
        cout << i << " ";
}