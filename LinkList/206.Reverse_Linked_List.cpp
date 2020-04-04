class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* cur = head;

        while (cur) {
            ListNode* nextP = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nextP;
        }
        return pre;
    }
}