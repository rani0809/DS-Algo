class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    if (nums.size() == 0)
        return nums.size();

    vector<int>::iterator m = nums.begin();  // m will mark the virtual "S.end()".
    for (int& val : nums) {
        auto it = lower_bound(nums.begin(), m, val);
        *it = val;
        if (it == m)
            m++;
    }
    
    return m - nums.begin();
}

};