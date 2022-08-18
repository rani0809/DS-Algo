class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> counter;
        priority_queue<int> q;
        int res = 0, removed = 0;
        
        for (auto a : arr) counter[a]++;
        for (auto c : counter) q.push(c.second);
        
        while (removed < arr.size() / 2) {
            removed += q.top();
            q.pop();
            res++;
        }
        
        return res;
    }
};