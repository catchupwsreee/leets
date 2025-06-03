class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        ListNode* curr = head;
        int len = 1;
        while (curr->next) {
            curr = curr->next;
            len++;
        }

        curr->next = head;
        k %= len;
        int stepsToNewHead = len - k;
        ListNode* newTail = curr;

        while (stepsToNewHead--) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};
