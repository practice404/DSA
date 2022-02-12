// https://leetcode.com/problems/matrix-cells-in-distance-order/

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<pair<int,pair<int,int>>> v;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                int dist=abs(i-rCenter) + abs(j-cCenter);
                v.push_back(make_pair(dist,make_pair(i,j)));
            }
        }
        sort(v.begin(),v.end());
        vector<vector<int>> ans;
        for(int i=0;i<v.size();i++){
            vector<int> temp;
            temp.push_back(v[i].second.first);
            temp.push_back(v[i].second.second);
            ans.push_back(temp);
        }
        return ans;
    }
};