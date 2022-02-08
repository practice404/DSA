// https://leetcode.com/problems/missing-number/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int i = 0;
        while(i < nums.size())
        {
            int correct_index = nums[i];
            if(nums[i] < nums.size() && nums[i] != nums[correct_index])
            {
                swap(nums[i], nums[correct_index]);
            }
            else
                i++;
        }
        
        
        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i] != i)
                return i;
        }
        
        return nums.size();
    }
};