//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    private:
    
    struct Node* reverse(struct Node* head){
        
        Node *prev = NULL;
        Node *forward = NULL;
        Node *curr = head;
        
        while(curr != NULL){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    
    // for calulating the length of linked list
    int length(struct Node* head){
        int count = 0; 
        struct Node* temp = head;
        
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }
       
    
    public:
    //Function to add two numbers represented by linked list.
struct Node* addTwoLists(struct Node* first, struct Node* second)
{
       // hame badi wali linked list pr kaam krna hai 
    if( length(first) < length(second) ){
        Node* temp = first;
        first = second; 
        second = temp; 
    }
      
     struct Node* f = reverse(first);
     struct Node* f1 = f;
     struct Node* s = reverse(second);
     struct Node* s1 = s;
     struct Node* prev = NULL; 
     int carry= 0;
       
       while(f1 != NULL || s1 != NULL){
           
           int f1_data =-1 , s1_data =-1;
        //   agr hamara f1 NULL pr aa gya hai toh 
           if(f1==NULL){
               f1_data = 0;
           }
           else
           {
               f1_data = f1->data;
           }
           
           
           if(s1==NULL){
               s1_data = 0;
           }
           else
           {
               s1_data = s1->data;
           }
           
           int sum = f1_data+ s1_data +  carry ;
           carry = sum/10;
           int digit = sum%10;   // this is the last digit of sum 
           f1->data = digit; // update f1 with last digit 
         
           prev=f1;
           f1 = f1->next;
           
           if(s1 != NULL){  //s1 ko aage badane krne se pehele dekh lo ki 
            s1 = s1->next;  // woh null pr toh nahi hai, kuki s1 chhota hai 
           }                // toh toh pehel punch jayega NULL pr
       }
        
       if(carry==1){
           struct Node* new_node = new Node(1);
           prev->next = new_node;
       } 
        
        return reverse(f);
        
        
     } 
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends