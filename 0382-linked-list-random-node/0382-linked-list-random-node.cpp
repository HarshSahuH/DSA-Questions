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
    
    vector<int> al; //al means arr list
    Solution(ListNode* head) {
        
        ListNode* temp = head;
        while(temp!=NULL){
            al.push_back(temp->val);
            temp=temp->next;
        }
        
    }
    
    int getRandom() { 
        int i = rand()%al.size();                                         
        return al[i];
    }
};

//agr hame rand function ki range 0 se n ke beech krni toh hum rand()%n kr denge ye ab hame 0 se n-1 ke beech ke number dega  

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */