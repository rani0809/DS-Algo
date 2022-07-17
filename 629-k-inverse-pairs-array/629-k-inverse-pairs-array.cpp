class Solution {
public:
    int kInversePairs(int n, int k) {
        long long int dp[n+1][k+1];
        int mod = 1000000007;
        for(int i = 0 ;i<=k;i++)dp[0][i] = 0;
        for(int i = 0 ;i<=n;i++)dp[i][0] = 1;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=k;j++){
                long long int val = (j-i>=0) ? dp[i-1][j-i] : 0;
                dp[i][j] = (dp[i][j-1] + dp[i-1][j] + (mod-val))%mod;
            }
        }
        return dp[n][k]%mod;
    }
};