// https://leetcode.com/problems/squares-of-a-sorted-array/

class Solution {
public:
    int last_negative(vector<int> & nums)
    {
        int lo = 0;
        int hi = nums.size()-1;
        int ans = -1;
        while(hi >= lo)
        {
            int mid = lo + (hi-lo)/2;
            if(nums[mid] < 0)
            {
                ans = mid;
                lo = mid + 1;
            }
            else
                hi = mid-1;
        }
        
        return ans;
    }
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;

        int ptr1 = last_negative(nums); // log(N)
        if(ptr1 != -1)
        {
            if(nums.size() == 1)
            {
                ans.push_back(nums[ptr1]*nums[ptr1]);
                return ans;
            }
            int ptr2 = ptr1 + 1;
            while(ptr1 >= 0 && ptr2 <= nums.size()-1) // O(N)
            {
                if(abs(nums[ptr1]) < nums[ptr2])
                {
                    ans.push_back(abs(nums[ptr1]));
                    ptr1--;
                }
                else if(abs(nums[ptr1]) == nums[ptr2])
                {
                    ans.push_back(abs(nums[ptr1]));
                    ans.push_back(nums[ptr2]);
                    ptr1--;
                    ptr2++;
                }
                else
                {
                    ans.push_back(nums[ptr2]);
                    ptr2++;
                }
            }

            while(ptr1 >= 0)
            {
                ans.push_back(abs(nums[ptr1]));
                ptr1--;
            }
            while(ptr2 < nums.size())
            {
                ans.push_back(nums[ptr2]);
                ptr2++;
            }
        }
        else
            ans = nums;
        
        for(auto & i : ans)
        {
            i = i*i;
        }

        return ans;
    }
};