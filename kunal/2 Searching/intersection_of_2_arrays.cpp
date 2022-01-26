// https://leetcode.com/problems/intersection-of-two-arrays/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        for(int i = 0; i < nums1.size(); i++)
        {
            if((i==0) || (nums1[i-1] != nums1[i]))
            {
                int val = nums1[i];
                int lo = 0;
                int hi = nums2.size()-1;
                
                while(hi>=lo)
                {
                    int mid = lo + (hi-lo)/2;
                    if(nums2[mid] == val)
                    {
                        ans.push_back(val);
                        break;
                    }
                    else if(nums2[mid] < val)
                        lo = mid + 1;
                    else
                        hi = mid - 1;
                }
            }
        }
        
        return ans;
    }
};