/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int solve(TreeNode* root, int& counter, int k){
        if(root == NULL){
            return -1;
        }
        
        //left
        int left = solve(root->left,counter,k);
        if(left != -1){
            return left;
        }
        
        //Node
        counter++;
        if(counter == k){
            return root->val;
        }
        
        //right
        return solve(root->right,counter,k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int counter = 0;
        return solve(root,counter,k);
    }
};

/*
T.C. O(N)
S.C. O(1) if we consider stack using when Recursive call happen then O(N)
*/