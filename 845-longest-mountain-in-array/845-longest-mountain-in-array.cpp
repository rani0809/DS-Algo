class Solution {
public:
    int longestMountain(vector<int>& A) {
        int maxLength = 0;
        int i = 1;
        
        while (i < A.size()) {
            int increasing = 0, decreasing = 0;
            
            while(i < A.size() && A[i - 1] < A[i]) i++, increasing++;
            while(i < A.size() && A[i - 1] > A[i]) i++, decreasing++;
            
            if (increasing > 0 && decreasing > 0) maxLength = max(maxLength, increasing + decreasing + 1);
            
            while(i < A.size() && A[i - 1] == A[i]) i++;
        }
        return maxLength;
    }
};