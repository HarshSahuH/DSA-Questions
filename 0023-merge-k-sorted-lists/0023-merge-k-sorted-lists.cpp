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
class cmp{
    public: 
    
    bool operator() (ListNode *a,ListNode *b){
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        
        priority_queue<ListNode*, vector<ListNode*>,cmp> q;
     
        
        for(int i=0; i<lists.size(); i++){
            
            if(lists[i]!=NULL){
                q.push(lists[i]);
            }
        }

        
        ListNode *ans = new ListNode(-1);
        ListNode *tail = ans;
        
        while(q.size()>0){
            ListNode *temp = q.top();
            q.pop();
            
            
            
             tail -> next = temp ;
            
            tail = temp ;
            
            if(temp->next!=NULL){
             q.push(temp->next);
            }
        }
        
        return ans->next;
    }
};