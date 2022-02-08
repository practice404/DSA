// https://leetcode.com/problems/first-missing-positive/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0;
        while( i < nums.size())
        {
            long long correct_index = 0LL + nums[i] - 1;
            if(nums[i] > 0 && nums[i] < nums.size() && nums[i] != nums[correct_index])
                swap(nums[i], nums[correct_index]);
            else
                i++;
        }

        for(int i=0; i<nums.size(); ++i)
        {
            if(nums[i] != i+1)
            {
                return i+1;
            }
        }
        
        return nums.size()+1;
    }
};