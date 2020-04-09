// Date:        2020.4.8
// Topic:       Linklist + math
// Todo:        make a summary

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pa = headA, * pb = headB;
        while(pa && pb) {
            if (pa == pb) {
                return pa;
            }
            pa = pa->next;
            pb = pb->next;
            if (!pa && !pb) break;
            if (!pa) pa = headB;
            if (!pb) pb = headA;
        }
        return nullptr;
    }
};
