// https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        for(auto i : nums)
        {
            hash[i]++;
        }
        
        vector<int> ans;
        int r = 0;
        for(int i=0; i<nums.size(); i++)
        {
            int second_num = target - nums[i];
            
            if(second_num != nums[i])
            {
                if(hash[second_num])
                {
                    r = target - nums[i];
                    ans.push_back(i);
                    break;
                }   
            }
            
            else
            {
                if(hash[second_num] > 1)
                {
                    r = target - nums[i];
                    ans.push_back(i);
                    break;
                }
                else
                    continue;
            }
        }
        
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == r && i != ans[0])
            {
            	ans.push_back(i);
            	break;
            }
        }
        
        return ans;
        
    }
};