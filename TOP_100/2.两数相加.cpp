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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dumpy(0);
        ListNode* tail = &dumpy;
        int carry = 0;
        while (l1 || l2 || carry) {
            int val = carry;      // Test Case {9,9,9} {1} -> {0,0,0,1} but {0,0,0,0}
            if (l1) val += l1->val;
            if (l2) val += l2->val;
            carry = val / 10;
            tail->next = new ListNode(val % 10);
            tail = tail->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        return dumpy.next;
    }
};
