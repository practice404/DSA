// https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        if(n%2) // odd
        {
            ans.push_back(0);
            for(int i = n; i > n/2 + 1; i--)
            {
                ans.push_back(i);
                ans.push_back(-i);
            }
        }

        else // even
        {
            for(int i = n; i > n/2; i--)
            {
                ans.push_back(i);
                ans.push_back(-i);
            }
        }

        return ans;


    }
};