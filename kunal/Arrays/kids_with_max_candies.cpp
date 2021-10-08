// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max_ = *max_element(candies.begin(), candies.end());
        vector<bool> ans;
        for(auto i:candies)
        {
            if(i+extraCandies >= max_)
                ans.push_back(true);
            else
                ans.push_back(false);
        }

        return ans;
    }
};