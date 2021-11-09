// https://leetcode.com/problems/maximum-subarray/


// modified kadane algo for all negative numbers

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN;
        int curr_sum = 0;
        bool is_all_negative = false;
        
        is_all_negative = all_of(nums.begin(), nums.end(), [](int x){return x < 0;});
        
        if(!is_all_negative)
        {
            for(auto i : nums)
            {
                curr_sum += i;
                if(curr_sum < 0)
                    curr_sum = 0;
                max_sum = max(max_sum,curr_sum);
            }
        }
        else
        {
            max_sum = *max_element(nums.begin(), nums.end());
        }
        
        
        return max_sum;
    }
};