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
TreeNode* minValue(TreeNode* root) {
    if (root == NULL)
        return root;
    
    TreeNode* temp = root;
    while (temp->left != NULL) {
        temp = temp->left;
    }
    return temp;
}

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode * dummy = root;
        if(root == NULL){
            return root;
        }
        
        if(root->val == key){ 
            //case 1 leaf node
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }
        
            //case 2 if root has one child either it is in right or it is in left
            if(root->left != NULL && root->right == NULL){
                TreeNode* temp =root->left;
                delete root;
                return temp;
            }
            if(root->left == NULL && root->right != NULL){
                TreeNode* temp = root->right;
                delete root;
                return temp;
                }
            //case 3 root has two child 
            if(root->left != NULL && root->right != NULL){
                int mini = minValue(root->right)->val;
                root->val = mini;
                root->right = deleteNode(root->right,mini);
                return root;
            }
        }
        
        else if(root->val > key){
            //left mein jao
            root->left = deleteNode(root->left,key);
            return root;
        }
        
        else{
            //right mein jao
            root->right = deleteNode(root->right,key);
            return root;
        }
        return dummy;
    }
};