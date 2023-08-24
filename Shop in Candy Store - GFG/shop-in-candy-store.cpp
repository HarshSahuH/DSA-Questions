//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        //step 1 Sort kr do Candies array ko
        sort(candies,candies+N);
        
        //minimum cost find karo
        int miniCost = 0;
        int buyCandy = 0;
        int freeCandy = N-1;
        
        while(buyCandy <= freeCandy){
            miniCost += candies[buyCandy++];
            freeCandy -= K;
        }
        
        //maximum cost find krne ke liye pehle sabse Expensive candy le lo baad mein free wali candy le lo
        int maxiCost=0;
        buyCandy = N-1;
        freeCandy = 0;
        while(freeCandy <= buyCandy){
            maxiCost += candies[buyCandy--];
            freeCandy += K;
        }
      
      return {miniCost,maxiCost};
    }
};

//T.C. O(NlogN) + O(N) + O(N) 
//S.C. O(1)

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends