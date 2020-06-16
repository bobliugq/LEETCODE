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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head, * slow = head;
        // when n = length of LinkList ?? 
        while (n--) {
            fast = fast->next;
        }
        // Test Case : [1, 2], 2 : Delete the head node
        if (fast == nullptr) {
            return head->next;
        }
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};
