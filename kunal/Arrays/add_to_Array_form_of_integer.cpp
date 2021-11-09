// https://leetcode.com/problems/add-to-array-form-of-integer/

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        
        vector<int> ans;
        
        reverse(num.begin(), num.end());

        int carry = 0;
        for(auto i : num)
        {
            int ld = k%10;
            k /= 10;
            
            int sum_ = i + ld + carry;
            ans.push_back(sum_%10);
            carry = sum_/10;
        }
        
        while(k>0)
        {
            int sum_ = k%10 + carry;
            ans.push_back(sum_%10);
            carry = sum_/10;
            k /= 10;
        }
        
         if(carry)
        {
            ans.push_back(carry);
            carry = 0;
        }
        
        
        reverse(ans.begin(), ans.end());
        
        return ans;
        
    }
};