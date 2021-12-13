// https://leetcode.com/problems/flipping-an-image/

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(auto &v : image)
        {
            for(auto &i : v)
            {
                if(i == 0)
                    i = 1;
                else
                    i = 0;
            }

            reverse(v.begin(), v.end());
        }

        return image;


    }
};