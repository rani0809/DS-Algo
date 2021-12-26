class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& P, int k) {
        auto euclidean = [](auto& p) { return p[0] * p[0] + p[1] * p[1]; };
        sort(begin(P), end(P), [&](auto& a, auto& b) { return euclidean(a) < euclidean(b); });
        P.resize(k);
        return P;
    }
};