// https://leetcode.com/problems/majority-element/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0;
        int target_count = nums.size()/2;
        
        for(int i = 0; i<nums.size()-1; ++i)
        {
            if(nums[i] == nums[i+1])
            {
                count++;
            }
            else
            {
                count++;
                if(count > target_count)
                    return nums[i];
                else
                    count = 0;
            }
        }
        // if came out of loop means the last two elements should be similar
        count++;
        return nums[nums.size()-1];
    }
};