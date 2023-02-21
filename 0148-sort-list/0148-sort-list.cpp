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
private:
        ListNode* findMid(ListNode *head)
       {
             ListNode* slow= head;
            // Node* fast= head;         jb ye kr raha hu toh seg falut aa raha hai ?? 
            ListNode* fast = head->next;
        
            while(fast != NULL && fast->next != NULL){ 
            slow = slow->next;
            fast = fast->next->next;
        }
        
            return slow;
        }
    
    
    ListNode* merge(ListNode* left, ListNode* right){
        
        if(left ==NULL) return right;
        
        if(right == NULL) return left;
        
        // dummy node hai isme sort hue node ko add krke return kara denge  
        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;
        
        while(left != NULL && right != NULL){
            
            if(left->val < right->val){
                temp->next = left;
                temp = left;
                left = left->next;
            }
            else{
                temp->next = right;
                temp = right;
                right = right->next;
            }
        }
        
        while(left != NULL){
            temp->next = left;
            temp = left;
            left = left->next; 
        }
        
         while(right != NULL){
            temp->next = right;
            temp = right;
            right = right->next; 
        }
        
        
        ans = ans->next;
        return ans;
        
    }

public:
    ListNode* sortList(ListNode* head) {
         if(head == NULL || head->next == NULL)
        return head;
        
        // step1 find mid
        ListNode *mid = findMid(head);
        
        ListNode *left = head;
        ListNode *right = mid->next;
        mid->next = NULL;
        
        // step2 recursive call 
        left = sortList(left);
        right = sortList(right);
        
        
        //step3 merge both halves
        ListNode *result  = merge(left,right);
        return result;
         
    }
};