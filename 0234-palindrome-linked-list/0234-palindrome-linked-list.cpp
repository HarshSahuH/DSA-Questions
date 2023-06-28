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
    ListNode* middleNode(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        
        //find the middle of the linked list 
        while(fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverseList(ListNode* head)
    {   
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nex = NULL;
        
        while(curr != NULL)
        {
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        
        if( head == NULL || head -> next  == NULL) return true;
        
        //find the middle of the linked list 
        ListNode* slow  = middleNode(head);
        
        //reverse the the right half 
        slow->next = reverseList(slow->next);
        
        //move slow pointer to right half
        slow = slow->next;
        
        //check for left half , right half equal or not 
        ListNode* temp = head;
        while(slow != NULL)
        {
            if(temp->val != slow ->val) return false;
            
            temp = temp->next;
            slow = slow->next;
        }
        return true;
        
        //this is optional if interviewr say that give back to me original                LinkedList
        ListNode* middle = middleNode(head);
        middle->next = reverseList(middle->next);
    }
};

//T.C. O(N/2) + O(N/2) + O(N/2) + O(N/2) + O(N/2)
