// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:
    int lower_bound(vector<int> & nums, int target)
    {
        int lo = 0;
        int hi = nums.size()-1;
        int ans = -1;
        while( hi >= lo)
        {
            int mid = lo + (hi-lo)/2;
            if(nums[mid] >= target)
            {
                ans = mid;
                hi = mid-1;
            }
            else
            {
                lo = mid+1;
            }
        }
        
        return ans;
    }
    int upper_bound(vector<int> & nums, int target)
    {
        int lo = 0;
        int hi = nums.size()-1;
        int ans = nums.size();
        while( hi >= lo)
        {
            int mid = lo + (hi-lo)/2;
            if(nums[mid] > target)
            {
                ans = mid;
                hi = mid-1;
            }
            else
            {
                lo = mid+1;
            }
        }
        
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        vector<int> ans(2,-1);
        if(nums.size() == 0)
            return ans;
        int l_b = lower_bound(nums,target);
        if( l_b != -1 && nums[l_b] == target)
        {
            int u_b = upper_bound(nums, target);
            u_b--;
            
            ans[0] = l_b;
            ans[1] = u_b;
            return ans;
        }
        return ans;
    }
};