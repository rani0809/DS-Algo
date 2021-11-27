class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int low = 0, high = num.size() - 1;
        while (low < high - 1) {
            int mid = (low + high) / 2;
            if (num[mid] > num[mid - 1] && num[mid] > num[mid + 1]) 
                return mid;
            else if (num[mid] > num[mid + 1]) 
                    high = mid - 1;
                 else 
                    low = mid + 1;    
        }
        return num[low] > num[high] ? low : high;
    }
};