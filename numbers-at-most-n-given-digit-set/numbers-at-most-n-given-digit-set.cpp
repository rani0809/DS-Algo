class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& D, int L) {
        auto s = to_string(L);
        int cnt = 0, N = size(s), M = size(D);
        for(int i = 1; i < N; i++) cnt += pow(M, i);
        for(int i = 0, j; i < N; i++) {
            for(j = 0; j < M && D[j][0] < s[i];j++) 
                cnt += pow(M, N-1-i);
            if(j >= M || D[j][0] != s[i]) return cnt;
        }
        return cnt+1;
    }
};