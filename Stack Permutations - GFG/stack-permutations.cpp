//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

//Apporach in this quesion can We create array B from array A using stack and stack operation 
//step1: aap ek stack lo , i=0 i is pointing on A; j=0 j is pointing on B
//stap2: push A[i] into stack 
//step3 :   agr (s.top() == B[j]) => true mtlb hum s.pop () + j++ kr denge 
//          re

class Solution{
public:
    int isStackPermutation(int N,vector<int> &A,vector<int> &B){
     
     stack<int>s;
     int j=0;   
     
     for(int i=0; i<N; i++){
         s.push(A[i]);
         
         if(s.top()==B[j]){
             while(s.size()>0 && s.top()==B[j]){
                 s.pop();
                 j++;
             }
         }
     }
     if(s.size()==0) return 1;
     else return 0;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        Solution ob;
        cout<<ob.isStackPermutation(n,a,b)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends