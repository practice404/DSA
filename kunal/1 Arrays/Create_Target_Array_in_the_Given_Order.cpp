// https://leetcode.com/problems/create-target-array-in-the-given-order/
class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> target(nums.size(),-1);
        for(int i=0; i<index.size(); i++)
        {
            int current_index = index[i];
            for(int j = target.size()-1; j>current_index; j--)
            {
                swap(target[j], target[j-1]);
            }
            
            target[current_index] = nums[i];
        }
        
        return target;
        
    }
};