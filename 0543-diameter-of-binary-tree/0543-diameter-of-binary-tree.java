/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int findHeight(TreeNode root){
        if(root == null){
            return 0;
        }
        int leftHeight = findHeight(root.left);
        int rightHeight = findHeight(root.right);

        return Math.max(leftHeight, rightHeight) + 1;
    }
    public int diameterOfBinaryTree(TreeNode root) {
        if( root == null){
            return 0;
        }
        

        int leftHeight = findHeight(root.left);
        int rightHeight = findHeight(root.right);
        int currentDiameter = leftHeight + rightHeight;

        int leftSubtreeDiameter = diameterOfBinaryTree(root.left);
        int rightSubtreeDiameter = diameterOfBinaryTree(root.right);

        int maxi = Math.max(currentDiameter, Math.max(leftSubtreeDiameter, rightSubtreeDiameter)); 

        return maxi;

    }
}