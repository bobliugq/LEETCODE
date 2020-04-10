// Date:        2020.4.9
// Topic:       LinkList + Sort
// Todo:        MergeSort


class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return nullptr;
        }
        ListNode* fast = head->next, * slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        fast = slow->next;
        slow->next == nullptr;
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(fast);
        
        return merge(l1, l2);
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dumpy(0);
        ListNode* tail = &dumpy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                tail = tail->next;
                l1 = l1->next;
            } else {
                tail->next = l2;
                tail = tail->next;
                l2 = l2->next;
            }
        }
        tail->next = l1 ? l1 : l2;
        return dumpy.next;
    }
};
