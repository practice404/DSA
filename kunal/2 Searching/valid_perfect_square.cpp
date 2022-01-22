// https://leetcode.com/problems/valid-perfect-square/

class Solution {
public:
    bool isPerfectSquare(int n) {
        int lo = 0, hi = n;
        long long mid = 0;
        while(lo<=hi)
        {
            mid = (lo + hi)/2;
            if(static_cast<long long>(mid*mid) == n)
                return true;
            else if(mid*mid < n)
                lo = mid+1;
            else
                hi = mid-1;
        }
        return false;
    }
};