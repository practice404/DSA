// https://leetcode.com/problems/find-the-highest-altitude/

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
     vector<int> pfsum(gain.size() + 1);

        for(int i = 1; i<=gain.size(); i++)
        {
            pfsum[i] = pfsum[i-1] + gain[i-1];
        }

        return *max_element(pfsum.begin(), pfsum.end());
    }
};