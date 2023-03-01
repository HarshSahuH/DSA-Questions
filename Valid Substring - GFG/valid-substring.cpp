//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
        if(s.size()==1)
        {
            return 0;
        }
        
        // step1 create ch stack and problem stack 
        stack<char> ch;
        stack<int>index;
        index.push(-1);
        
        int len = 0;
        
        for(int i=0; i<s.length(); i++){
            if(s[i]=='('){ //opening hai toh push kr do ch stack mein 
               ch.push(s[i]); // or hum mann kr chal rahe hai ki ye hame problem dega 
               index.push(i);
            }
            else{
                if(!ch.empty() && ch.top()=='('){
                    ch.pop();
                    index.pop(); //ye kuki hame ch.top()pr '(' mil gya iska mtlab ye problem nahi kr raha 
                    len = max(len , i-index.top());
                }
                else{
                    index.push(i);
                }
            }
        }
        return len;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}

// } Driver Code Ends