// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        
        int rows = grid.size();
        int cols = grid[0].size();
        
        int r = 0;
        int c = cols-1;
        
        while((r < rows) && (c >= 0)) // increasing rows and decreasing cols
        {
            if(grid[r][c] < 0)
            {
                count += (rows - r);
                c --;
            }
            else
            {
                r++;
            }
        }
        
        return count;
    }
};