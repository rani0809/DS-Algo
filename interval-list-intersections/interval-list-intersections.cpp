class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
    vector<vector<int>> res;
    for (auto i = 0, j = 0; i < A.size() && j < B.size();) {
        if (A[i][1] < B[j][0])
            ++i;
        else if (B[j][1] < A[i][0])
            ++j;
        else {
            res.push_back({max(A[i][0], B[j][0]), min(A[i][1], B[j][1])});
            if (A[i][1] < B[j][1])
                ++i;
            else
                ++j;
        }
    }
    return res;
} 
};