// quick sort
#include<bits/stdc++.h>
using namespace std;

void print(vector<int>&v)
{
    for(auto i : v)
        cout << i << " ";
    cout << endl;
}

void qsort(vector<int> &nums, int lo, int hi)
{
    if(lo >= hi)
        return;

    int s = lo;
    int e = hi;
    int m = s + (e-s)/2;
    int pivot = nums[m];

    while(s <= e)
    {
        while(nums[s] < pivot)
            s++;
        while(nums[e] > pivot)
            e--;
        if(s <= e) // there's a chance that condition get violated in above operations
        {
            swap(nums[s], nums[e]);
            s++;
            e--;
        }
    }

    qsort(nums, lo, e); // going from lo -> e becuse of above loop e < s
    qsort(nums, s, hi); // because of above loop s > e
}


int main()
{
    vector<int> v = {5,4,3,2,3,1};
    qsort(v,0,v.size()-1);
    print(v);
}