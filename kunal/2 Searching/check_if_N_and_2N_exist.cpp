// https://leetcode.com/problems/check-if-n-and-its-double-exist/


class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        // binary search will take O(nlog(n))
        // so doing hashing O(n)
        
        unordered_map<int,int> mp;
        
        for(int i = 0; i<arr.size(); i++)
            mp[arr[i]] = i+1;
        
        
        for(int i = 0; i<arr.size(); i++)
        {
            if((mp[2*arr[i]]) && (i+1 != mp[2*arr[i]]))
                return true;
        }
        
        return false;
    }
};