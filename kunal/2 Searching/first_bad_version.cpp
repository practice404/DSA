// https://leetcode.com/problems/first-bad-version/

class Solution {
public:
    int firstBadVersion(int n) {
        
        int lo = 1;
        int hi = n;
        
        while(hi > lo)
        {
            int mid = lo + (hi - lo)/2;
            if(isBadVersion(mid))
                hi = mid;
            else
                lo = mid+1;
        }
        
        return hi;
        
    }
};