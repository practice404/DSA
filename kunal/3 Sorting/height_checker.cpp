// https://leetcode.com/problems/height-checker/

class Solution {
public:
    int heightChecker(vector<int>& h) {
    vector<int> exp;
    int n = h.size();
    int num = 0;
    for(int i = 0; i<n; i++){
        exp.push_back(h[i]);
    }
    sort(h.begin() , h.end());
    for(int i = 0; i<n; i++){
       if(exp[i] != h[i]){
           num++;
       }
    }
    return num;
    }
};
