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
     int solve(TreeNode* root,int &res){
        
        // base condition 
        if(root==NULL)
        return 0;
        
        // hypothesis
        int lef = solve(root->left,res);
        int rig = solve(root->right,res);
        
        // induction 
        int temp = 1+max(lef,rig);
        int ans = 1+lef+rig;
        res = max(res,ans);
        
        return temp;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int result = INT_MIN;
        solve(root,result);
        return result-1;
    }
};