/*
class Node{
    int data;
    Node next;

    Node(int x){
        data = x;
        next = null;
    }
}
*/
class Solution {
    public Node insertAtEnd(Node head, int x) {
        Node temp = new Node(x);
        
        if(head == null) return temp;
        
        Node mover = head;
        while(mover.next != null){
            mover = mover.next;
        }
        
        mover.next = temp;
        
        return head;
    }
}