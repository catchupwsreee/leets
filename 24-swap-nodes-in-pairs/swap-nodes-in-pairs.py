class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def swapPairs(self, head):
        dummy = ListNode(0)
        dummy.next = head
        current = dummy

        while current.next and current.next.next:
            first = current.next
            second = current.next.next

            # Swap nodes
            first.next = second.next
            second.next = first
            current.next = second

            # Move to the next pair
            current = first

        return dummy.next
