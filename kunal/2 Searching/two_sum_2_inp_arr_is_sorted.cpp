// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        vector<int> ans(2,-1);
        
        for(int i = 0; i < numbers.size(); ++i)
        {
            int num = numbers[i];
            int lo = i+1;
            int hi = numbers.size()-1;
            
            while(lo <= hi)
            {
                int mid = lo + (hi-lo)/2;
                if(numbers[mid] == (target-num))
                {
                    ans[0] = i+1;
                    ans[1] = mid+1;
                    return ans;
                }
                else if(numbers[mid] < (target-num))
                {
                   lo = mid+1;
                }
                else
                    hi = mid-1;
            }
        }
        
        return ans;
        
    }
};