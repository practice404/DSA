// https://leetcode.com/problems/shuffle-the-array/

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int l = 0;
        int r = n;
        vector<int> ans;
        for(int i = 0; i<n;i++ )
        {
            ans.push_back(nums[l]);
            ans.push_back(nums[r]);
            l++;
            r++;
        }

        return ans;
    }
};