// https://leetcode.com/problems/third-maximum-number/submissions/

class Solution {
public:
    void bubblesort(vector<int> & nums2, int n)
    {
        // 3*O(N) = O(N)
        bool swapped = false;
        
        for(int i = 0; i < n; ++i)
        {
            for(int j = 1; j < nums2.size() - i; ++j)
            {
                if(nums2[j] < nums2[j-1])
                {
                    swap(nums2[j], nums2[j-1]);
                    swapped = true;
                }
            }

            if(!swapped)
                break;
        }
    }
    
    int thirdMax(vector<int>& nums) 
    {
        unordered_map<int,int> mp; // accessing and inputting take O(1)

        for(auto i : nums) // O(N)
            mp[i]++;
        
        vector<int> nums2;
        
        for(auto i = mp.begin(); i != mp.end(); i++) // O(N)
        {
            nums2.push_back(i->first);
        }

        if(nums2.size() >= 3)
        {
            bubblesort(nums2, 3);
            return nums2[nums2.size()-3];
        }
            
        else
        {
            bubblesort(nums2, nums2.size());
            return nums2[nums2.size()-1];
        }
            
        
        return -1; //  never gonna come out of if-else
        
    }
};