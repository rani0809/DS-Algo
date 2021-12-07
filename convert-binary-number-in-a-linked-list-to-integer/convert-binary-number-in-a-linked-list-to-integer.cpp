/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        string s;
        for(; head; head = head -> next) s.push_back(head -> val+'0');
        int ans = 0;
        for(int i = size(s)-1, p = 1; i >= 0; i--, p *= 2)
            ans += p * (s[i] == '1');
        return ans;
    }
};