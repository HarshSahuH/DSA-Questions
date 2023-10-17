class Solution {
    void dfs(int node, vector<int>& leftChild, vector<int>& rightChild, vector<bool>& visited, int& visitedCount) {
         visited[node] = true;
        visitedCount++;
        
        if (leftChild[node] != -1 && !visited[leftChild[node]]) {
            dfs(leftChild[node], leftChild, rightChild, visited, visitedCount);
        }
        
        if (rightChild[node] != -1 && !visited[rightChild[node]]) {
            dfs(rightChild[node], leftChild, rightChild, visited, visitedCount);
        }
    }
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
       vector<int> inDegree(n, 0);
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) {
                if (inDegree[leftChild[i]] != 0) {
                    return false; // Node already has a parent
                }
                inDegree[leftChild[i]]++;
            }
            
            if (rightChild[i] != -1) {
                if (inDegree[rightChild[i]] != 0) {
                    return false; // Node already has a parent
                }
                inDegree[rightChild[i]]++;
            }
        }
        
        int rootCount = 0;
        int root = -1;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                rootCount++;
                root = i;
                if (rootCount > 1) {
                    return false; // Multiple roots found
                }
            }
        }
        
        if (rootCount == 0) {
            return false; // No root found
        }
        
        vector<bool> visited(n, false);
        int visitedCount = 0;
        dfs(root, leftChild, rightChild, visited, visitedCount);
        
        return visitedCount == n;
    }
};