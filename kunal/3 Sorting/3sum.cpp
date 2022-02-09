// https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> ans;
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i<n-2; i++) // now array is sorted
        {
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            
            int lo = i+1;
            int hi = n-1;
            while(hi > lo)
            {
                if(hi < n-1 && nums[hi] == nums[hi+1])
                {
                    hi--;
                    continue;
                }
                int sum = nums[i] + nums[lo] + nums[hi];
                if(sum == 0)
                {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[lo]);
                    temp.push_back(nums[hi]);
                    ans.push_back(temp);
                    hi--;
                }
                else if(sum > 0)
                {
                    hi--;
                }
                else
                    lo++;
            }
        }
        
        return ans;
        
    }
};