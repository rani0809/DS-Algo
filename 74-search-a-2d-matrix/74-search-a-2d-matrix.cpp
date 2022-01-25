class Solution {
public:
     bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if (!n) return false;
        int m = matrix[0].size();
        if (!m) return false;
        int l = 0, r = n * m - 1;
        while (l < r) {
            int med = (l + r) / 2;
            (matrix[med / m][med % m] < target) ? (l = med + 1) : (r = med);
        }
        return matrix[l / m][l % m] == target;
    }
    
   

};