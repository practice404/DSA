// https://leetcode.com/problems/arranging-coins/

class Solution {
public:
    int arrangeCoins(int n) {
        // hi is 65537 because solving the quadratic eqn of (n(n+1)/2 = INT_MAX)
        int ans = binary_search(1, 65537, n);
        return ans;
    }

    int binary_search(int lo, int hi, int target)
    {   
        int ans = 0;
        while(hi >= lo)
        {
            int mid = lo + (hi-lo)/2;
            long long coins = mid*1LL*(mid+1)/2;

            if(coins == target)
                return mid;
            else if(coins > target)
                hi = mid - 1;
            else
            {
                ans = mid;
                lo = mid + 1;
            }
        }

        return ans;
    }
};