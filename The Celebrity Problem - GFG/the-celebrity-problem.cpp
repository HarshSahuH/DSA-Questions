//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    bool Knows(int a, int b,vector<vector<int> >& M){
        return M[a][b];
    }
    public:
    
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> s;
        for(int i=0; i<n ;i++){
            s.push(i);
        }
        
        int count = 0;
        while(count < n-1){
            
            int first = s.top();
            s.pop();
            
            int second = s.top();
            s.pop();
            
            if(Knows(first,second,M)){ // Kya first second ko janta hai 
                s.push(second);
            }
            else{
                s.push(first); // fisrt, second ko nahi janta toh second celebrity 
            }                  // nahi ho sakta , kuki celebrity ko sb jante hai 
        
            count++;
        }
        
        
        int celebrity = s.top();
        
        for(int i=0; i<n; i++){
            if(i != celebrity && (Knows(celebrity,i,M) || !Knows(i,celebrity,M)) ){
                return -1;
            }
        }
        return celebrity;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends