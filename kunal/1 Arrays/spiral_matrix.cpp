// https://leetcode.com/problems/spiral-matrix/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int cols = matrix[0].size();
        int rows = matrix.size();
        
        vector<int> ans;
        
        int row_start = 0;
        int row_end = rows-1;
        int col_start = 0;
        int col_end = cols-1;
        
        
        while(row_start <= row_end && col_start <= col_end)
        {
            for(int i = col_start; i<=col_end; i++)
                ans.push_back(matrix[row_start][i]);
            row_start++;
            
            for(int i = row_start; i<=row_end; i++)
                ans.push_back(matrix[i][col_end]);
            col_end--;
            
            if(row_start <= row_end)
            {
                for(int i = col_end; i>=col_start; i--)
                    ans.push_back(matrix[row_end][i]);
                row_end--;
            }
            
            if(col_start <= col_end)
            {
                for(int i = row_end; i>=row_start; i--)
                     ans.push_back(matrix[i][col_start]);
                col_start++;  
            }
            
        }
        
        return ans;
        
    }
};