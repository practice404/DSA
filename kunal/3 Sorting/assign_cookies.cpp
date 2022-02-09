// https://leetcode.com/problems/assign-cookies/

class Solution {
public:
    bool lower_bound(vector<int> & nums, int target)
    {
        int lo = 0;
        int hi = nums.size()-1;
        
        while(hi >= lo)
        {
            int mid = lo + (hi - lo)/2;
            if(nums[mid] >= target)
                return true;
            else
                lo = mid+1;
        }
        
        return false;
    }
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count = 0;
        sort(g.begin(), g.end(), [](int a, int b){return a>b;}); // sort in dec
        sort(s.begin(), s.end()); //sort in inc
        
        for(auto i : g)
        {
            if(lower_bound(s, i))
            {
                count ++;
                s.pop_back();
            }
        }
        
        return count;
        
    }
};