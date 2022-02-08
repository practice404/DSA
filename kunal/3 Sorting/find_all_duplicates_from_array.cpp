// https://leetcode.com/problems/find-all-duplicates-in-an-array/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int i = 0;
        while( i < nums.size())
        {
            int correct_index = nums[i] - 1;
            if(nums[i] != nums[correct_index])
                swap(nums[i], nums[correct_index]);
            else
                i++;
        }
        
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] != i+1)
                ans.push_back(nums[i]);
        
        return ans;
    }
};