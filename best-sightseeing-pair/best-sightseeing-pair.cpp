class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A, int res = 0) {
  for (auto j = 1, max_i = A[0] - 1; j < A.size(); ++j, --max_i) {
    res = max(res, A[j] + max_i);
    max_i = max(max_i, A[j]);
  }
  return res;
}
};