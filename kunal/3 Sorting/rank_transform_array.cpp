// https://leetcode.com/problems/rank-transform-of-an-array/

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> mp;
        vector<int> temp = arr;
        sort(arr.begin(), arr.end());

        int count = 1;
        for(int i = 0; i < arr.size(); i++)
        if(mp[arr[i]] == 0)
        {
            mp[arr[i]] = count;
            count++;
        }
        for(int i = 0; i < temp.size(); i++)
            temp[i] = mp[temp[i]];
        
        return temp;
            
    }
};
