// https://leetcode.com/problems/fair-candy-swap/

#include<bits/stdc++.h>

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& a, vector<int>& b) {
        
        vector<int> ans;
        
        int a_sum = accumulate(a.begin(), a.end(), 0);
        int b_sum = accumulate(b.begin(), b.end(), 0);
        
        int delta = (b_sum - a_sum)/2;
        
        unordered_set<int> s;
        
        for(auto i : b)
            s.insert(i);
        
        for(auto i : a)
            if(s.find(i+delta) != s.end())
            {
                ans.push_back(i);
                ans.push_back(i+delta); 
                break;
            }
                
        return ans;
    }
};