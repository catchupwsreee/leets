class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseKGroup(self, head, k):
        def reverseLinkedList(head, k):
            prev, curr = None, head
            while k:
                nxt = curr.next
                curr.next = prev
                prev = curr
                curr = nxt
                k -= 1
            return prev

        count = 0
        ptr = head
        while ptr and count < k:
            ptr = ptr.next
            count += 1
        if count == k:
            reversedHead = reverseLinkedList(head, k)
            head.next = self.reverseKGroup(ptr, k)
            return reversedHead
        return head
