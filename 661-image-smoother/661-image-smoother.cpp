class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int m = M.size(), n = M[0].size(); 
        vector<vector<int>> ans(m, vector<int>(n, 0)); 
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int cnt = 0; 
                for (int ii = i-1; ii <= i+1; ++ii) {
                    for (int jj = j-1; jj <= j+1; ++jj) {
                        if (0 <= ii && ii < m && 0 <= jj && jj < n) {
                            ans[i][j] += M[ii][jj]; 
                            ++cnt; 
                        }
                    }
                }
                ans[i][j] /= cnt; 
            }
        }
        return ans; 
    }
};