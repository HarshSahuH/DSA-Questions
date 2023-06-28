/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        unordered_set<ListNode*> ss;
        
        ListNode* node = head;
        while(node != NULL)
        {
            if(ss.find(node) != ss.end()){
                return node;
            }
            else{
                ss.insert(node);
                node = node->next;
            }
        }
      return NULL;  
    }
};