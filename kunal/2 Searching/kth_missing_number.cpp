// https://leetcode.com/problems/kth-missing-positive-number/

/*

- arr[i] - (i+1) => number of missing elements till that index
- find the first index where the missing number count exceeds k
- returns the sum of that index and k

*/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int lo = 0;
        int hi = arr.size()-1;
        
        while(hi >= lo)
        {
            int mid = lo + (hi-lo)/2;
            
            if(arr[mid] - mid -1 < k)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        
        return (k + lo);
    }
};