// merge sort

#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> & nums, int l, int mid, int r)
{
    int l_size = mid - l + 1;
    int r_size = r - mid;

    vector<int> L(l_size);
    vector<int> R(r_size);

    for(int i = 0; i < l_size; i++)
        L[i] = nums[i+l];

    for(int i = 0; i < r_size; i++)
        R[i] = nums[i + mid +1];

    // merging both arrays inplace
    int l_i = 0;
    int r_i = 0;
    int k = 0; // pointer to move on nums array for replacing elements

    while(l_i < l_size && r_i < r_size)
    {
        if(L[l_i] < R[r_i])
        {
            nums[l + k] = L[l_i];
            l_i++;
            k++;
        }
        else if(L[l_i] == R[r_i])
        {
            nums[l+k] = L[l_i];
            k++;
            l_i++;
            nums[l+k] = R[r_i];
            k++;
            r_i++;
        }
        else
        {
            nums[l+k] = R[r_i];
            r_i++;
            k++;
        }
    }

    while(l_i < l_size)
    {
        nums[l+k] = L[l_i];
        k++;
        l_i++;
    }
    while(r_i < r_size)
    {
        nums[l+k] = R[r_i];
        k++;
        r_i++;
    }
}

void merge_sort(vector<int>&nums, int l, int r)
{
    if(l == r) // return when only single element remains
        return;
    int mid = (l+r)/2;

    merge_sort(nums, l, mid);
    merge_sort(nums, mid+1, r);
    merge(nums, l, mid, r);
}

int main()
{
    vector<int> v = {38,27,43,3,9,82,10};
    merge_sort(v, 0, v.size()-1);

    for(auto i : v)
        cout << i << " ";
}