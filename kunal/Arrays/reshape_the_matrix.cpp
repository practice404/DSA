// https://leetcode.com/problems/reshape-the-matrix/

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        
        if(m*n != r*c)
            return mat;
        else
        {
            vector<int> temp;
            for(auto i : mat)
            {
                for(auto j : i)
                {
                    temp.push_back(j);
                }
            }
            
            int row = 0;
            int col = 0;
            
            vector<vector<int>> ans(r,vector<int> (c));

            for(auto i : temp)
            {
                ans[row][col] = i;
                if(row < r)
                    col++;
                if(col == c)
                {
                    col = 0;
                    row++;
                }
            }
            
            return ans;
        }
    }
};