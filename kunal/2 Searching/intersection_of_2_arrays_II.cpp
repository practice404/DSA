// https://leetcode.com/problems/intersection-of-two-arrays-ii/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        unordered_set<int> s;
        
        for(auto i : nums1)
            s.insert(i);
        
        for(auto i : nums1)
            mp1[i]++;
        
        for(auto i : nums2)
            mp2[i]++;
        
        for(auto i : s)
        {
            int count = min(mp1[i], mp2[i]);
            while(count)
            {
                ans.push_back(i);
                count--;
            }
        }
        
        return ans;
    }
};