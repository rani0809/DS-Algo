class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int n = nums.size();
if (n < 2) return n;

int pos = 2;
for (int i = 2; i < n; ++i)
    if (nums[i] != nums[pos - 2]) nums[pos++] = nums[i];

return pos;  
    }
};