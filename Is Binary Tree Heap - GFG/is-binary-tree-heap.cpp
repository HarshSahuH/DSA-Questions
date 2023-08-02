//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User Function template for C++

// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/



class Solution {
    int countNodes(Node* tree) {
        
        if(tree == NULL)
            return 0;
        
        int ans = 1 + countNodes(tree->left) + countNodes(tree->right);
        return ans;
    }
    
    bool isCBT(Node* tree,int index, int TotalNodes)
    {
        if(tree == NULL) 
        return true;
        
        if(index >= TotalNodes)
        return false;
        else
        {
            bool left = isCBT(tree->left, 2*index+1,TotalNodes);
            bool right = isCBT(tree->right, 2*index+2,TotalNodes);
            
            return (left && right);
        }
    }
    
    bool isMaxHeap(Node* tree)
    {
        if(tree->left == NULL && tree->right == NULL)
        return true;
        
        if(tree->right == NULL)
        {
            return (tree->data > tree->left->data);
        }
        
        if(tree->left != NULL && tree->right != NULL)
        {
            bool left = isMaxHeap(tree->left);
            bool right = isMaxHeap(tree->right);
            
            return (left && right && (tree->data > tree->left->data && tree->data > tree->right->data) );
        }
    }
    
  public:
    bool isHeap(struct Node* tree) {
        
        if(tree == NULL)
        return true;
        
        int index = 0;
        int TotalNode = countNodes(tree);
        
        if(isCBT(tree,index,TotalNode) && isMaxHeap(tree))
        return true;
        else
        return false; 
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if (ob.isHeap(root))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}
// } Driver Code Ends