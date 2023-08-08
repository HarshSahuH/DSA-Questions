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
class Solution{
    void RightView(TreeNode* root, vector<int> & result, int level)
    {
        if(root == NULL)
            return;
        
        if(level == result.size())
            result.push_back(root->val);
        
        RightView(root->right,result,level+1);
        RightView(root->left,result,level+1);
    }
    
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        RightView(root,result,0);
        return result;
    }
}; 