// https://leetcode.com/problems/single-element-in-a-sorted-array/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // nums should contain total odd numbers of elements
        int lo = 0;
        int hi = nums.size()-1;

        if(nums.size() == 1)
            return nums[0];
        
        while(hi >= lo)
        {
            int mid = (hi+lo)/2;
            
            if(mid == 0) // mid is point to first element of nums
            {
                if(nums[mid] != nums[mid+1]) // no element behind
                    return nums[mid];
            }

            if(nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1])
                return nums[mid];
            else
            {   
                if(nums[mid] == nums[mid-1] && ((mid-lo)%2))
                {
                    lo = mid + 1;
                }
                else if(nums[mid] == nums[mid-1] && !((mid-lo)%2))
                {
                    hi = mid - 2;
                }
                else if(nums[mid] == nums[mid+1] && ((hi-mid)%2))
                {
                    hi = mid - 1;
                }
                else if(nums[mid] == nums[mid+1] && !((hi-mid)%2))
                {
                    lo = mid + 2;
                }
            }
        }

        return -1; // it should never come out of loop 
    }
};