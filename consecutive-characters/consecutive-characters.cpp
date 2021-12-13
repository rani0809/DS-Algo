class Solution {
public:
    int maxPower(string& s) {
        int ans = 0;
        for(int i = 0; i < size(s); i++) {
            int j = i + 1;
            while(j < size(s) && s[j] == s[j-1])  // find longest substring starting at i
                j++;
            ans = max(ans, j-i);                  // ans holds length of longest substring containing same char
        }
        return ans;
    }
};