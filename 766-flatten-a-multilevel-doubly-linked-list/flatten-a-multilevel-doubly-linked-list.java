class Solution {
    public Node flatten(Node head) {
        if (head == null) return head;

        Node dummy = new Node(0, null, head, null);
        Node prev = dummy;

        Deque<Node> stack = new ArrayDeque<>();
        stack.push(head);

        while (!stack.isEmpty()) {
            Node curr = stack.pop();
            prev.next = curr;
            curr.prev = prev;

            if (curr.next != null) {
                stack.push(curr.next);
            }
            if (curr.child != null) {
                stack.push(curr.child);
                curr.child = null;
            }

            prev = curr;
        }

        dummy.next.prev = null;
        return dummy.next;
    }
}
