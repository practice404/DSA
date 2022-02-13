// https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        // AP should be increasing or decreasing in order
        sort(arr.begin(), arr.end());
        double diff = abs(arr[0] - arr[1]);
        
        for(int i = 1; i < arr.size()-1; i++)
            if(abs(arr[i] - arr[i+1]) != diff)
                return false;
        return true;
    }
};