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
    ListNode* reverseBetween(ListNode* head, int m, int n) 
{
	auto **pivot{&head->next}, **start{&head};

	for(; --n && --m; pivot = &(*(start = pivot))->next); 
	for(; n--; swap(*start, (*pivot)->next), swap(*start, *pivot)); 

	return head;
}
};