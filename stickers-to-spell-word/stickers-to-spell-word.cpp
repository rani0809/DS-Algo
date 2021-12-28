class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int n = target.size(); 
        vector<uint> dp(1 << n, -1); 
        dp[0] = 0; 
        for (int mask = 0; mask < (1 << n); ++mask) 
            if (dp[mask] != -1) 
                for (auto& sticker : stickers) {
                    int mask0 = mask; 
                    for (auto& ch : sticker) 
                        for (int j = 0; j < n; ++j) 
                            if (ch == target[j] && (mask0 & (1<<j)) == 0) {
                                mask0 ^= 1 << j; 
                                break; 
                            }
                    dp[mask0] = min(dp[mask0], 1 + dp[mask]);
                }
        return dp.back(); 
    }
};