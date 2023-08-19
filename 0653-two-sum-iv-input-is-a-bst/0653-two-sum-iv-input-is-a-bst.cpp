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
    void inOrderTraversal(TreeNode* root, vector<int>& inOrderVal){
        if(root == NULL){
            return ;
        }
        
        //left
        inOrderTraversal(root->left,inOrderVal);
        //Node
        inOrderVal.push_back(root->val);
        //right 
        inOrderTraversal(root->right,inOrderVal);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> inOrderVal;
        inOrderTraversal(root,inOrderVal);
        
        int i=0,j=inOrderVal.size()-1;
        
        while(i<j){
            if(inOrderVal[i]+inOrderVal[j] == k){
                return true;
            }
            else if(inOrderVal[i] + inOrderVal[j] > k){
                j--;
            }
            else{
                i++;
            }
        }
        return false;
    }
};

/*
T.C. O(N) for inserting value in inordered way into vector + O(N) for traversing the vector
S.C. O(H)
*/