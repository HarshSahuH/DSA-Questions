/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        //My Approach T.C. O(K*n)  where n is the number of nodes in the linked list.
        if(head == NULL || head->next == NULL || k==0) return head;
        
        //compute the length
        ListNode* curr = head;
        int length = 1;
        while(curr->next != NULL){
            length++;
            curr = curr->next;
        }
       
        //go till that node
        curr->next = head;
        k = k % length;
        k = length - k; 
        while( k != 0) 
        {
            curr = curr->next;
            k--;
        }
        //make a head node and break connection 
        head = curr->next;
        curr->next = NULL;
        
        return head;
    }
};