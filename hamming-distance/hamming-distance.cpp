class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        int num = x^y;
        while (num) {
            res += num % 2;
            num >>= 1;
        }
        return res;
    }
};