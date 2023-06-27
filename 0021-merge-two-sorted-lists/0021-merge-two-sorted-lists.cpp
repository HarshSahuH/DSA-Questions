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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if(list1 == NULL  && list2 == NULL)return NULL;
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        
        ListNode* res = new ListNode();
        ListNode* dummy = res;
        ListNode* a = list1;
        ListNode* b = list2;
      
        while(a!= NULL && b!=NULL)
        {
            if(a->val == b->val){
                dummy->next = a;
                a = a->next;
                dummy = dummy->next;
            }
            else if(a->val < b->val){
                dummy->next = a;
                a = a->next;
                dummy = dummy->next;
            }
            else{
                dummy->next = b;
                b=b->next;
                dummy = dummy->next;
                
            }
        }
        
        while(a!=NULL)
        {
            dummy->next = a;
            a = a->next;
            dummy = dummy->next;
        }
        while(b!=NULL)
        {
            dummy->next = b;
            b = b->next;
            dummy = dummy->next;
        }
        
        ListNode* result = res->next;  // Assign the merged list to result
        delete res;  // Delete the initial dummy node
        return result;
    }
};

//T.C. O(n+m) n = lenght of list1 and m = length of l2