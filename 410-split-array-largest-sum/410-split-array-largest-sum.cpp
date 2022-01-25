class Solution {
public:
    bool check(int bar, int m, vector<int> &nums) {

    int count = 0, sum = 0;
    for (auto it : nums){
        sum += it;
        if (sum == bar) { count++; sum = 0; }
        else if (sum > bar) {count++; sum = it; }
    }
    if (sum > 0) count++;
    if (count <= m) return true;
    return false;
}

int splitArray(vector<int> &nums, int m) {

    int beg = INT_MIN, end = 0, ans;
    for (auto it : nums) {
        end += it;
        if (it > beg) beg = it;
    }
    while (beg <= end) {
        int mid = beg + (end - beg) / 2;
        if (check(mid, m, nums)){
            ans = mid;
            end = mid - 1;
        }
        else beg = mid + 1;
    }
    return ans;
}

};