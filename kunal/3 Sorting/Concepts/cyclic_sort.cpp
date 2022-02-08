#include<bits/stdc++.h>
using namespace std;

// applicable when the array contains element from 1 to N
// O(N)

void cycle_sort(vector<int> &v)
{
	int i = 0;
    while( i < nums.size())
    {
        int correct_index = nums[i] - 1;
        if(nums[i] > 0 && nums[i] < nums.size() && nums[i] != nums[correct_index])
            swap(nums[i], nums[correct_index]);
        else
            i++;
    }
}

int main()
{
	vector<int> v {3,5,2,1,4};
	cycle_sort(v);

	for(auto i : v)
		cout<<i<<" ";
}