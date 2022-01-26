// https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/

class Solution {
public:
    int specialArray(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        int lo = 0;
        int hi = 100;
        
        while(hi >= lo)
        {
            int mid = lo + (hi-lo)/2;
            
            auto lb = lower_bound(nums.begin(), nums.end(),mid);
            if (nums.end() - lb == mid)
                return mid;
            else if(nums.end() - lb > mid)
                lo = mid+1;
            else
                hi = mid-1;
        }
        
        return -1;
        
    }
};