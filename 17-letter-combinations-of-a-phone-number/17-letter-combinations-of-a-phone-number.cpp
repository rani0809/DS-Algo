class Solution {
    vector<string>map{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}, res;
public:
    void backTrack(string& s, int l, int r,  string curr) {
        if(l >= r) {
            if(l==r)res.push_back(curr);
            return;
        }
        string m = map[s[l]-'0'];
        for(int j = 0; j<m.size(); j++) {
            backTrack(s, l+1, r, curr+m[j]);
        }
    }
    vector<string> letterCombinations(string s) {
        if(s.size()==0) return {};
        backTrack(s, 0, s.size(), "");
        return res;
    }
};