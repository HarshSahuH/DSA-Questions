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

//T.C. O(2n) S.C. O(1) by stiver
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        
        //find length of list
        int sz = 0;
        ListNode* temp = head;
        while(temp != NULL )
        {
            sz = sz+1;
            temp = temp->next;
        }
        
        //edge case 
        if(sz == n)
        {
          ListNode* node = head;
          head = head->next;
          delete (node);
          return head;  
        }
        
        
        ListNode* del = head;
        int substraction = sz-n;
        for(int i=1; i< substraction; i++){
            del = del->next;
        }
        
        ListNode* temp1 = del->next;
        del->next = del->next->next;
        delete temp1;
        
        return head;
    }
};