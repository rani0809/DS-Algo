class Solution {
public:
    int m, n, N;
    int t[101][101][201];
    bool check(string s1, string s2, string s3, int i, int j, int k) {
        if(i >= m && j >= n && k >= N) //solution
            return true;
        
        if(k >= N) //other string didn't get consumed whole
            return false;
            
        if(t[i][j][k] != -1)
            return t[i][j][k];
        
        return t[i][j][k] = ((s1[i]==s3[k] && check(s1, s2, s3, i+1, j, k+1)) || (s2[j]==s3[k] && check(s1, s2, s3, i, j+1, k+1)));
    }
    bool isInterleave(string s1, string s2, string s3) {
        memset(t, -1, sizeof(t));
        m = s1.length();
        n = s2.length();
        N = s3.length();
        
        return check(s1, s2, s3, 0, 0, 0);
    }
};