class Solution {
    void dfs(int node, vector<vector<int>> &adjList, vector<int> &visited){
        visited[node] = 1;
        for(auto it : adjList[node]){
            if(!visited[it]){
                dfs(it,adjList,visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
       vector<vector<int>> adjList(V, vector<int>(V, 0));
        //this is code for change matrix into adjacency list 
        for(int i=0; i<V; i++) {
            for(int j=0; j<V; j++){
                if(isConnected[i][j] == 1 && i!=j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        
         vector<int> visited(V, 0);
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