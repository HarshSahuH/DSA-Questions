//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    void dfs(int node, vector<vector<int>> &adjList, int visited[]){
        visited[node] = 1;
        for(auto it : adjList[node]){
            if(!visited[it]){
                dfs(it,adjList,visited);
            }
        }
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        
        vector<vector<int>> adjList{V};
        //this is code for change matrix into adjacency list 
        for(int i=0; i<V; i++) {
            for(int j=0; j<V; j++){
                if(adj[i][j] == 1 && i!=j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        
        int visited[V] = {0};
        int result=0;
        for(int i=0; i<V; i++){
            if(!visited[i]){
                result++;
                dfs(i,adjList,visited);
            }
        }
        return result;
    }
};
//t.c. o(N) + O(v+2E)
// s.c. O(N) + O(N)


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends