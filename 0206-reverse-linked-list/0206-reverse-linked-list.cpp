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
    
     ListNode* reverseHelper(ListNode* curr, ListNode* newHead)
     {
        if (curr == nullptr) {
            return newHead;
        }
        
        ListNode* next = curr->next;
        curr->next = newHead;
        
        return reverseHelper(next, curr);
    }
    
public:
    
    ListNode* reverseList(ListNode* head) {
        
        if(head == NULL || head->next == NULL) return head;
        
        return reverseHelper(head , NULL);
        
    }
};