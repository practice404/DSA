#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rotationCountOfSortedArray(vector<int>& arr) 
    {
        int lo = 0;
        int hi = arr.size()-1;
        int n = arr.size();

        while(lo <= hi)
        {
            int mid = lo + (hi - lo)/2;

            // case 1:
            if(arr[mid] > arr[mid+1])
                return (mid + 1)%n; // since count will be index of mid+1
            else if(arr[mid] < arr[mid-1])
                return (mid-1+1)%n; // since count will be index of mid+1
            else if(arr[lo] > arr[mid])
                hi = mid - 1;
            else
                lo = mid + 1; 
        }

        return 0;

    }
};


int main()
{
    Solution sol;
    vector<int> arr = {7, 9, 11, 12, 15};
    cout << sol.rotationCountOfSortedArray(arr) << endl;
}