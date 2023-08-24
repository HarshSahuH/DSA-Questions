//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

 static bool cmp(pair<pair<int,int>,int>a,pair<pair<int,int>,int>b){
        return a.first.second<b.first.second;
    }

class Solution{
public:
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        
        vector<pair<pair<int,int>,int>>meet;
        vector<int> ans;
        for(int i=0;i<N;i++){
            meet.push_back({{S[i],F[i]},i});
        }
        
        
        sort(meet.begin(),meet.end(),cmp);
        
        
        ans.push_back(meet[0].second+1);
        int endAns=meet[0].first.second;
        for(int i=1;i<N;i++){
            if(meet[i].first.first>endAns){
                ans.push_back(meet[i].second+1);
                endAns=meet[i].first.second;
            }
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//T.C. O(N) + O(NlogN) + O(N) = O(NlogN) 
//S.C. O(N)


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends