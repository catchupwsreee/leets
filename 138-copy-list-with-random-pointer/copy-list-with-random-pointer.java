class Solution {
    public Node copyRandomList(Node head) {
        if (head == null) return null;
        
        Node current = head;
        while (current != null) {
            Node copy = new Node(current.val);
            copy.next = current.next;
            current.next = copy;
            current = copy.next;
        }
        
        current = head;
        while (current != null) {
            if (current.random != null)
                current.next.random = current.random.next;
            current = current.next.next;
        }
        
        current = head;
        Node pseudoHead = new Node(0);
        Node copyCurrent = pseudoHead;
        while (current != null) {
            Node copy = current.next;
            copyCurrent.next = copy;
            copyCurrent = copy;
            current.next = copy.next;
            current = current.next;
        }
        
        return pseudoHead.next;
    }
}
