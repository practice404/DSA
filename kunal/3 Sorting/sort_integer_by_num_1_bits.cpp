// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/

class Solution {
public:
    int count_1(int n)
    {
        int count = 0;
        if(n == 0)
            return 0;
        while(n > 0)
        {
            n = n & (n-1);
            count++;
        }

        return count;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> ans;
        vector<pair<int,int>> hash;

        for(int i = 0; i < arr.size(); i++)
        {   
            int count = count_1(arr[i]);
            hash.push_back({arr[i], count});
        }

        auto cmp = [](pair<int, int> a , pair<int,int> b)
        {
            if(a.second != b.second)
                return a.second < b.second;
            return a.first < b.first;
        };

        sort(hash.begin(), hash.end(), cmp);
        for(auto i : hash)
            ans.push_back(i.first);
        return ans;
    }
};