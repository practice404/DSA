// https://leetcode.com/problems/maximum-population-year/

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int interval = 2050 - 1950 + 1;
        vector<int> in(interval);
        for(auto v : logs)
        {
            int l = v[0];
            int r = v[1];


            for(int i = l; i<r; i++)
            {
                in[i-1950]++;
            }
        }

        int max_ = *max_element(in.begin(), in.end());
        auto it = find(in.begin(), in.end(), max_);

        int year = (it - in.begin()) + 1950;

        return year;

    }
};