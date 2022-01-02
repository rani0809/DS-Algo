class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int ans = 0, cnt[60] = {0};
        for (int i = 0; i < time.size(); i ++) cnt[time[i] % 60] += 1;
        for (int i = 1; i< 30; i ++) ans += cnt[i] * cnt[60 - i];
        return ans + cnt[0] * (cnt[0] - 1) / 2 + cnt[30] * (cnt[30] - 1) / 2;
    }
};