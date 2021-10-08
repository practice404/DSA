// https://leetcode.com/problems/count-items-matching-a-rule/


class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int count = 0;

        int prop_index = 0;

        if(ruleKey == "type")
            prop_index = 0;
        else if(ruleKey == "color")
            prop_index = 1;
        else
            prop_index = 2;


        for(auto i : items)
        {
            if( i[prop_index] == ruleValue )
                count++;
        }

        return count;

    }
};