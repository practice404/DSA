class Solution {
public:
    int mySqrt(int n) {
        // taking lo = 0 instead of 1 because if input is INT_MAX then (INT_MAX + 1)/2 cant be stored in int
        int lo = 0, hi = n;
        long long mid = 0;
        while(lo<=hi)
        {
            mid = (lo + hi)/2;
            if(static_cast<long long>(mid*mid) == n)
                return mid;
            else if(mid*mid < n)
                lo = mid+1;
            else
                hi = mid-1;
        }
        return hi;
    }
};

// general soln

class Solution {
public:
    double mySqrt(int n) {
        double epsilon = 1e-6;
        int lo = 0, hi = n;
        long long mid = 0;
        while(hi - lo > epsilon)
        {
            mid = (lo + hi)/2;
            if(static_cast<long long>(mid*mid) < n)
                lo = mid;
            else
                hi = mid;
        }
        return lo;
    }
};
