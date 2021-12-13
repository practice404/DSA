// https://leetcode.com/problems/number-of-good-pairs/

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        vector<int> hash(105,0);
        for(int i = 0; i < nums.size(); i++)
        {
            hash[nums[i]]++;
        }
        
        int good_pairs = 0;
        
        for(int i = 0; i<105; i++)
        {
            good_pairs += (hash[i] * (hash[i] - 1))/2;
        }
        
        return good_pairs;
    }
};