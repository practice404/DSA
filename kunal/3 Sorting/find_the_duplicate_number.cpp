// https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i = 0;
        while(i < nums.size())
        {
            int correct_index = nums[i] - 1;
            if(nums[i] != nums[correct_index])
                swap(nums[i], nums[correct_index]);
            else
                i++;
        }
        
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] != i+1)
                return nums[i];
        
        return -1; // never come out of loop

    }
};