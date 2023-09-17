//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int isPallindrome(long long int N){
        vector<int> ans;
        while(N){
            int remainder = N%2;
            ans.push_back(remainder);
            N = N/2;
        }
        
        int i=0;
        int j=ans.size()-1;
        
        while(i<j){
            if(ans[i] == ans[j]){
                i++;
                j--;
            }
            else{
                return 0;
            }
        }
        return 1;
    }
    
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        Solution ob;
        cout << ob.isPallindrome(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends