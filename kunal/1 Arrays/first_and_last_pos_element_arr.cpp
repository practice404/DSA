// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
         vector<int> ans;
        
        int l_index, r_index;
        
        auto l_it = lower_bound(nums.begin(), nums.end(), target);

        if(l_it != nums.end())
        {
        	if(*l_it != target)
        	{
            	l_index = -1;
            	r_index = -1;
        	}
        	else
        	{
            	auto r_it = upper_bound(nums.begin(), nums.end(), target);
        
            	l_index = l_it - nums.begin();
        
            	int repeated_times = r_it - l_it;
        
            	r_index = l_index + repeated_times - 1;
        
        	}
		}

		else
		{
			l_index = -1;
            r_index = -1;
		}

        
			
		ans.push_back(l_index);
        ans.push_back(r_index);        
        
        
        return ans;
        
        
    }
};