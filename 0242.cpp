class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
        int letter;
        vector<int> letterCountS(26, 0);
        vector<int> letterCountT(26, 0);
        for(int i=0; i<s.length(); i++) {
            letter = s[i] - 'a';
            letterCountS[letter] += 1;
            letter = t[i] - 'a';
            letterCountT[letter] += 1;
        }
        return letterCountS ==  letterCountT;

        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());
        // return s == t;
    }
};