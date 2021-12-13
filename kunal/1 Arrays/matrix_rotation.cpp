// https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/

class Solution {

    // for rotating 90deg, first reverse the matrix then take the transpose
    void rotateMatrixClockwiseInPlace(vector<vector<int>>& mat)
    {
        // * flip vertically
        reverse(begin(mat), end(mat));

        // * transpose
        for (int i = 1; i < size(mat); i++)
            for (int j = 0; j < i; j++)
                swap(mat[i][j], mat[j][i]);
    }

   public:
    bool findRotation(vector<vector<int>>& mat, const vector<vector<int>>& target)
    {
        // note you can compare the vector / matrices directly using == operator

        if (mat == target) return true;
        rotateMatrixClockwiseInPlace(mat);
        if (mat == target) return true;
        rotateMatrixClockwiseInPlace(mat);
        if (mat == target) return true;
        rotateMatrixClockwiseInPlace(mat);
        return mat == target;
    }
};