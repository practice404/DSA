// https://leetcode.com/problems/minimum-absolute-difference/

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        int min_diff = INT_MAX;
        for(auto i = 0; i < arr.size()-1; i++)
        {
            if(abs(arr[i] - arr[i+1]) < min_diff)
                min_diff = abs(arr[i] - arr[i+1]);
        }
        
        for(int i = 0; i < arr.size(); i++)
        {
            bool is_present = binary_search(arr.begin(), arr.end(), arr[i] + min_diff);
            if(is_present)
            {
                ans.push_back({arr[i], arr[i]+min_diff});
            }
        }

        return ans;
    }
};
