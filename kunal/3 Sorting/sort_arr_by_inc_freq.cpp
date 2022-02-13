// https://leetcode.com/problems/sort-array-by-increasing-frequency/

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for(auto i :  nums)
            mp[i]++;
        vector<pair<int, int>> hash;
        for(auto it = mp.begin(); it != mp.end(); it++)
            hash.push_back({it->first, it->second});

        auto cmp = [](pair<int, int> a , pair<int,int> b)
        {
            if(a.second != b.second)
                return a.second < b.second;
            return a.first > b.first;
        };

        sort(hash.begin(), hash.end(), cmp);
        for(auto i : hash)
        {
            while(i.second--)
                ans.push_back(i.first);
        }

        return ans;
    }
};