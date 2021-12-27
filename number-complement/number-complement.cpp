class Solution {
public:
    int findComplement(int num) {
        int i = 31;
        while((num & 1 << i) == 0) i--;   // skip the left 0 bits till we reach the 1st set bit from left
        while(i >= 0)
            num ^= 1 << i--;              // flip all bits by XORing with 1
        return num;
    }
};