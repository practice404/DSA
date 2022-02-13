// https://leetcode.com/problems/make-two-arrays-equal-by-reversing-sub-arrays/
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        if(arr.size() != target.size())
            return false;
        sort(arr.begin(), arr.end());
        sort(target.begin(), target.end());
        
        for(int i = 0; i < arr.size(); i++)
        {
            if(arr[i] != target[i])
                return false;
        }
        
        return true;
    }
};