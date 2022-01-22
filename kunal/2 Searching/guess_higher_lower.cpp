// https://leetcode.com/problems/guess-number-higher-or-lower/

class Solution {
public:
    int guessNumber(int n) {
        
        int lo = 1;
        int hi = n;
        
        while(hi >= lo)
        {
            int mid = lo + (hi - lo) /2;
            if(guess(mid) == 0)
                return mid;
            else if(guess(mid) == -1)
                hi = mid-1;
            else
                lo = mid+1;
        }
        
        return 0;
        
    }
};