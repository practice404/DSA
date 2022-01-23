// https://www.geeksforgeeks.org/find-position-element-sorted-array-infinite-numbers/


#include<bits/stdc++.h>
using namespace std;

int binary_search(vector<int>&arr, int lo, int hi, int target)
{
    while(hi >= lo)
    {
        int mid = lo + (hi-lo)/2;
        if(arr[mid] == target)
            return mid;
        else if(arr[mid] > target)
            hi = mid - 1;
        else
            lo = mid + 1 ;
    }

    return -1;
}

int main()
{
    vector<int> arr = {3, 5, 7, 9, 10, 90, 100, 130, 140, 160, 170, 190, 340};
    int target = 140;


    int lo = 0;
    int hi = 1;
    int val = arr[0];
 
    // Find h to do binary search
    while (arr[hi] < target)
    {
        lo = hi;      
        hi = hi*2;
    }

    cout << binary_search(arr, lo, hi, target);
}