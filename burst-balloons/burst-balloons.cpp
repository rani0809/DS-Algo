class Solution {
    public:
        int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        // dp[i][j]=max( dp[i][j], dp[i][x-1]+nums[i-1]*nums[x]*nums[j+1]+dp[x+1][j] )
        // dp[i][j] means max coins in range [i,j].
        for(int len=1;len<=n;len++)
            for(int start=1;start<=n-len+1;start++)
            {
                int end=start+len-1;
                for(int x=start;x<=end;x++)
                    dp[start][end]=max(dp[start][end],dp[start][x-1]+nums[start-1]*nums[x]*nums[end+1]+dp[x+1][end]);
            }
        return dp[1][n];   
        }
    };