// https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/

class Solution {
public:
    int maxProduct(vector<int>& v) {
        int n = v.size();
        bool swapped = false;
        for(size_t i = 0; i < 2; ++i)
        {
            for(size_t j = 1; j < n - i; ++j)
            {
                if(v[j] < v[j-1])
                {
                    swap(v[j], v[j-1]);
                    swapped = true;
                }
            }

            if(!swapped)
                break;
        }

        return (v[n-1]-1)*(v[n-2]-1);
    }
};