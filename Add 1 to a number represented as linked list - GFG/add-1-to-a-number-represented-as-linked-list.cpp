//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    private: 
    Node* reverse(Node *head){
        
        Node *forward = NULL;
        Node *prev =NULL;
        Node *temp = head;
        
        while(temp!=NULL){
            forward = temp->next;
            temp->next = prev;
            prev = temp; 
            temp = forward;
        }
        return prev;
    }
    public:
    Node* addOne(Node *head) 
    {
        Node *head1 = reverse(head);
        
        Node *temp = head1;
        Node *prev = NULL;
        int sum = 0, carry = 0;
        bool flag = true;
        
        while(temp!=NULL){
            sum = temp->data + carry;
            
            if(flag){
                sum+=1;
                flag=false;
            }
            
            
            if(sum>9){
                carry = sum/10;
                temp->data = sum%10;
                
            }
            else{
                temp->data = sum;
                carry = 0;
            }
            prev = temp;
            temp = temp->next;
        }
        
        if(carry!=0){
            Node *neww = new Node(carry);
            prev->next = neww;
            neww=NULL;
        }
        
        return reverse(head1);
        
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends