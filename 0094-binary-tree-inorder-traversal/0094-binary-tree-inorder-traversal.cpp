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
/*
Time Complexity (TC):
The time complexity of the inorder traversal algorithm is O(N), where N is the number of nodes in the binary tree. This is because, in the worst case, we need to visit all the nodes of the binary tree once. The time complexity of both the inorderTraversal function and the inOrder function is O(N) since they both perform the same traversal.

Space Complexity (SC):
The space complexity of the algorithm is also O(N). This is because of the space used by the recursion stack during the traversal. In the worst case scenario, the maximum number of function calls that can be stored in the call stack is equal to the height of the binary tree. In an unbalanced binary tree, the height can be equal to N (the number of nodes), leading to O(N) space complexity. In a balanced binary tree, the height is log(N), which would still result in O(N) space complexity.

Additionally, the space complexity includes the space used to store the result vector, which can hold N elements (all the nodes' values), resulting in an additional O(N) space.
*/


class Solution {
    void inorder(TreeNode* root, vector<int>& result)
    {
        if(root == NULL) return;
        
        //LNR
        inorder(root->left,result);
        result.push_back(root->val);
        inorder(root->right,result);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
       vector<int> result;
       inorder(root,result);
        return result;
    }
};