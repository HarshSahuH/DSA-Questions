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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> result;
        if(root == NULL) return result;
        
        queue<TreeNode*> q;
        q.push(root);
        bool LeftToRight = true;
        
        while(!q.empty())
        {
          int x = q.size();
          vector<int> temp(x);  
          for(int i=0; i<x; i++)
          {
              TreeNode* tempNode = q.front();
              q.pop();
               
              int index = LeftToRight ? i : x-i-1;
              temp[index] = tempNode->val;
              
              if(tempNode->left != NULL)
                  q.push(tempNode->left);
              
              if(tempNode->right != NULL)
                  q.push(tempNode->right);
          }
          LeftToRight = !LeftToRight;
          result.push_back(temp);  
        }
      return result;
    }
};