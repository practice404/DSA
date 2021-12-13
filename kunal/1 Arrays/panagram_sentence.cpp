// https://leetcode.com/problems/check-if-the-sentence-is-pangram/

// can be solved by hashing too

class Solution {
public:
    bool checkIfPangram(string sentence) {
        set<char> s(sentence.begin(), sentence.end());
        if(s.size() == 26)
            return true;
        return false;

    }
};