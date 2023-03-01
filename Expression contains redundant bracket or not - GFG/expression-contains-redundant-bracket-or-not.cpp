//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    int checkRedundancy(string str) {
        
        stack<char> s;
        
        for(int i=0; i<str.length(); i++){
            
            if(str[i]==')'){
                char top = s.top();
                s.pop();
                
                int flag = 1;
                
                while(s.size()>0 && top != '('){
                    if(top=='+' || top=='-' || top=='*' || top=='/'){
                        flag = 0;
                    }
                    top = s.top();
                    s.pop();
                }
                if(flag==1){
                    return 1;
                }
            }
            
            else{
              s.push(str[i]);  // push open parenthesis '(',
             }              // operators and operands to stack 
        }
        
        return 0;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
    
        string s; 
        cin>>s;
        
        Solution obj;
        int res = obj.checkRedundancy(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends