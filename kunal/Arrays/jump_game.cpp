// https://leetcode.com/problems/jump-game/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size=nums.size();
        if(size==1)
            return true;
        if(nums[0]==0)
            return false;
        int c=nums[0];
        for(int i=1;i<size;i++)
        {
            c--;
  
            c=max(c,nums[i]);
            if(c==0 && i==size-1)
                return true;
            if(c<=0)
                return false;
        }
    
        return true;

    }
};