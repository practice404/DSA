// https://leetcode.com/problems/relative-sort-array/

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, bool> is_present;
        unordered_map<int, int> count;
        vector<int> ans;
        for(auto i : arr2) // O(n)
            is_present[i] = true;
        
        for(auto i : arr1) // O(n)
        {
            if(is_present[i])
            {
                count[i]++;
            }
            
        }
        
        for(auto i : arr2)
            while(count[i]--)
                ans.push_back(i);

        auto begin_ptr = ans.size();
        
        for(auto i : arr1)
            if(!is_present[i])
                ans.push_back(i);
        
        sort(ans.begin() + begin_ptr, ans.end());

        return ans;
    }
};