//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    long long solve(int N, vector<int> &A, vector<int> &B) {
        
        sort(A.begin() , A.end());
        sort(B.begin() , B.end());
        
        long long sumA = 0;
        long long sumB = 0;
        
        vector<int> Aodd;
        vector<int> Aeven;
        vector<int> Bodd;
        vector<int> Beven;
        
        for(int i=0; i<N; i++){
            
            sumA += A[i];
            sumB += B[i];
            
            if(A[i]%2==0){
                Aeven.push_back(A[i]);
            }
            else{
                Aodd.push_back(A[i]);
            }
            
             if(B[i]%2==0){
                Beven.push_back(B[i]);
            }
            else{
                Bodd.push_back(B[i]);
            }
        }
        
        if( (sumA != sumB) || (Aeven.size() != Beven.size()) )
        {
            return -1;
        }
        
        long long  ans = 0;
        
        for(int i=0; i<Aeven.size(); i++){
            ans += abs(Aeven[i]-Beven[i]);
        }
        
        for(int i=0; i<Bodd.size(); i++){
            ans += abs(Aodd[i]-Bodd[i]);
        }
        
        return ans/4;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        
        vector<int> B(N);
        Array::input(B,N);
        
        Solution obj;
        long long res = obj.solve(N, A, B);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends