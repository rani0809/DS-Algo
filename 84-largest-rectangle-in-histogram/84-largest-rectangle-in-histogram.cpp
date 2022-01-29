 class Solution {
    public:
        int largestRectangleArea(vector<int>& height) {
    height.push_back(0);
    const int size_h = height.size();
    stack<int> stk;
    int i = 0, max_a = 0;
    while (i < size_h) {
        if (stk.empty() || height[i] >= height[stk.top()]) stk.push(i++);
        else {
            int h = stk.top();
            stk.pop();
            max_a = max(max_a, height[h] * (stk.empty() ? i : i - stk.top() - 1));
        }
    }
    return max_a;
}
    };