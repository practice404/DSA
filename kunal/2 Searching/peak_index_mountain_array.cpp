// https://leetcode.com/problems/peak-index-in-a-mountain-array/


class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int lo = 0;
        int hi = arr.size()-1;
        int ans = -1;
        while(hi >= lo)
        {
            int mid = lo + (hi-lo)/2;
            if(arr[mid] < arr[mid+1])
                lo = mid + 1;
            else if(arr[mid] > arr[mid+1])
            {
                ans = mid;
                hi = mid-1;
            }
        }
        
        return ans;
    }
};