// https://leetcode.com/problems/rotate-array/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp = nums;
        for(int i =0; i<temp.size(); i++)
        {
            nums[(i+k)%n] = temp[i];
        }
    }
};