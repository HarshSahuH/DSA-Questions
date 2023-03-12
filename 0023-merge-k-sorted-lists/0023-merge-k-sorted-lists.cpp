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
    
    bool operator() (ListNode *a , ListNode *b){
        return a->val > b->val;
    }
    
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
    priority_queue<ListNode* , vector<ListNode*> , cmp> q ;

    // Firstly, we enter all the K Nodes into our Min-Heap

    for(int i = 0 ; i < lists.size() ; i++)
    {
        if(lists[i] != NULL)
            q.push(lists[i]) ;
    }

    // Dummy Pointer's Nexy will point to the Head of our K Merged Sorted Linkedlist

    ListNode *dummy = new ListNode(-1) ;

    // Tail pointer will help us to add Nodes into our K Merged Sorted LinkedList

    ListNode *tail = dummy ;

    // While Loop will run till our the size of our Priority-Queue not becomes 0(zero)

    while(q.size() )
    {
        // We pop the Topmost Element from our Priority-Queue and store it in Temp pointer

        ListNode *temp = q.top() ;
        q.pop() ;

        // Tail's Next points to Temp

        tail -> next = temp ;

        // After that, Tail Pointer is moved to Temp

        tail = temp ;

        // We enter Temp's Next Node into our Priority-Queue if it exists

        if(temp -> next != NULL)
            q.push(temp -> next) ;
    }

    // At the end, we return Dummy's Next which contains the Head of our Merged K Sorted LinkedList

    return dummy -> next ;
    }
};


/*
Time Complexity:  O(N*LogK)
Space Complexity: O(K)
*/