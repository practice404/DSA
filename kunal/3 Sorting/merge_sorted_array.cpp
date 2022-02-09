// https://leetcode.com/problems/merge-sorted-array/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        vector<int> temp;
        int i = 0;
        int j = 0;
        
        while(i < m && j < n)
        {
            if(nums1[i] < nums2[j])
            {
                temp.push_back(nums1[i]);
                i++;
            }
            else if(nums1[i] == nums2[j])
            {
                temp.push_back(nums1[i]);
                temp.push_back(nums2[j]);
                i++;
                j++;
            }
            else if(nums1[i] > nums2[j])
            {
                temp.push_back(nums2[j]);
                j++;
            }
        }
        
        if(j < n)
        {
            while(j < n)
            {
                temp.push_back(nums2[j]);
                j++;
            }
        }
        else if(i < m)
        {
            while(i < m)
            {
                temp.push_back(nums1[i]);
                i++;
            }
        }
        
        nums1 = temp;
    }
};