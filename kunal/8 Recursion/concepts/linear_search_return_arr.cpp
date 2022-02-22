#include<bits/stdc++.h>
using namespace std;



vector<int> linear_search(vector<int> & nums, int start, int target)
{
    vector<int> res;
    if(start == nums.size()) // base condition
        return res;
    if(nums[start] == target)
        res.push_back(start);

    vector<int>prev_answers = linear_search(nums, ++start, target);
    for(auto i : prev_answers)
        res.push_back(i);

    return res;
}

int main()
{
   vector<int> a = {1,2,3,3,3,4,4,5,11};
   // vector<int> res1;
   auto res = linear_search(a,0,3);
   for(auto i : res)
    cout << i << endl;
}