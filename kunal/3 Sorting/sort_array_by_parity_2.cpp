// https://leetcode.com/problems/sort-array-by-parity-ii/

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> odd;
        
        vector<int> even;
        
        for(int i = 0; i < n; i++)
        {
            if(arr[i] % 2 == 0)
            {
                even.push_back(arr[i]);
            }
            else
            {
                odd.push_back(arr[i]);
            }
        }
        
        int o = 0;
        
        int e = 0;
        
        arr.clear();
        
        for(int i = 0; i < n; i++)
        {
            if(i % 2 == 0)
            {
                arr.push_back(even[e]);
                
                e++;
            }
            else
            {
                arr.push_back(odd[o]);
                
                o++;
            }
        }
        
        return arr;
        
    }
};