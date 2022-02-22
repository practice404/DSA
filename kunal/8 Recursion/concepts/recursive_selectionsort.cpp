#include<bits/stdc++.h>
using namespace std;

void ssort(vector<int> & nums, int i, int j, int max_index)
{
    if(i == nums.size())
        return;
    if(j < nums.size() - i)
    {
        if(nums[j] > nums[max_index])
                max_index = j;
        ssort(nums, i, ++j, max_index);
    }
    else
    {
        swap(nums[max_index], nums[nums.size()-1-i]);
        max_index = 0;
        ssort(nums, ++i,0, max_index);
    }

    /*
    for(int i = 0; i < nums.size(); i++)
    {
        int max_index = 0;
        for(int j = 0; j < nums.size() - i; j++)
            if(nums[j] > nums[max_index])
                max_index = j;
        swap(nums[max_index], nums[nums.size()-1-i]);
    }
    */
}

int main()
{
    vector<int> v = {4,3,2,8,1};
    ssort(v,0,0,0);
    for(auto i : v)
        cout << i << " ";
}