// https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/

// sort
// hasing 👇


class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> hash(102,0);
        vector<int> ans;
        for(auto i : nums)
            hash[i]++;
        
        for(int i = 0; i < nums.size(); i++)
        {
            int sum = 0;
            for(int j = 0; j<nums[i]; j++)
            {
                sum += hash[j];
            }
            
            ans.push_back(sum);
        }
        
        return ans;
    }
};