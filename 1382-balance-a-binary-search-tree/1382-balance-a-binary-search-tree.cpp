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
    void inorderTraversal(TreeNode* root,vector<int>& inorder){
            if(root == NULL){
                return ;
            }
            
            inorderTraversal(root->left,inorder);
            inorder.push_back(root->val);
            inorderTraversal(root->right,inorder);
        }
    TreeNode* ConvertToBST(int s,int e,vector<int> inorder){
            if(s>e){
                return NULL;
            }
        
        int mid = (s+e)/2;
        TreeNode* node = new TreeNode(inorder[mid]);
        node->left = ConvertToBST(s,mid-1,inorder);
        node->right= ConvertToBST(mid+1,e,inorder); 
        
        return node;    
    } 
    
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        inorderTraversal(root,inorder);
            
        return ConvertToBST(0,inorder.size()-1,inorder);
    }
};